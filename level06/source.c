#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h> 

int auth(char *login, unsigned int serial)
{
    int     len;                // [ebp-0xc]
    int     serial_expected;    // [ebp-0x10]
    int     i;                  // [ebp-0x14]

    login[strcspn(login, "\n")] = '\0';
    len = strnlen(login, 32);
    if (len <= 5)
        return (1);
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
    {
        puts("\033[32m.--------------------------.");
        puts("\033[31m| !! TAMPERING DETECTED !!  |");
        puts("\033[32m'--------------------------'");
        return (1);
    }
    serial_expected = (login[3] ^ 0x1337) + 0x5eeded;
    for (i = 0; i < len; i++)
    {
        if (login[i] <= 0x1f)
            return (1);
        serial_expected += (login[i] ^ serial_expected) * 0x539;
    }
    if (serial == serial_expected)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    unsigned int    serial;             // [esp+0x28]
    char            login[32];          // [esp+0x2c]  fgets lee 0x20=32 bytes

    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");
    printf("-> Enter Login: ");
    fgets(login, 32, stdin);
    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial: ");
    scanf("%u", &serial);
    if (auth(login, serial) == 0)
    {
        puts("Authenticated!");
        system("/bin/sh");
        return (0);
    }
    return (1);
}