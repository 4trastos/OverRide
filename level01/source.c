#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char a_user_name[256];                          // Variable global en .bss

int verify_user_pass(char *password)
{
    return (strncmp(password, "admin", 5));
}

int verify_user_name()
{
    puts("verifying username....\n");
    return (strncmp(a_user_name, "dat_wil", 7));
}

int main(void)
{
    char password_buffer[64];                   // [esp+0x1c]

    memset(password_buffer, 0, 64);
    puts("********* ADMIN LOGIN PROMPT *********\n");
    printf("Enter Username: \n");

    fgets(a_user_name, 256, stdin);

    if (verify_user_name() == 0)
    {
        puts("Enter Password: ");
        fgets(password_buffer, 100, stdin);     // ¡VULNERABILIDAD! Lee 100 en un buffer de 64
        verify_user_pass(password_buffer);
    }
    
    printf("nope, incorrect username...\n");
    return (1);
}