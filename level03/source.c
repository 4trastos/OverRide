#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     decrypt(unsigned int diff)
{
    unsigned int    canary;         // [ebp-0xc] Stack Canary
    char            encrypted[] = {
        0x51, 0x7d, 0x7c, 0x75,
        0x60, 0x73, 0x66, 0x67,
        0x7e, 0x73, 0x66, 0x7b,
        0x7d, 0x7c, 0x61, 0x33,
        0x00
    };

    for (int i = 0; i < strlen(encrypted); i++)
        encrypted[i] ^= diff;

    if (strncmp(encrypted, "Congratulations!", 17) == 0)
        system("/bin/sh");
    else
        puts("\nInvalid Password");
}

void    test(int user_input, unsigned int param)
{
    unsigned int    diff;           // [ebp-0xc]

    diff = param - user_input;
    if (diff > 0x15)
    {
        decrypt(rand());
    }
    else
    {
        switch(diff)
        {
            case 0:  decrypt(diff); break;
            case 1:  decrypt(diff); break;
            case 2:  decrypt(diff); break;
            // ... hasta case 20 (0x14)
            case 20: decrypt(diff); break;
        }
    }
}

int main(void)
{
    int     user_input;             // [esp+0x1c]

    srand(time(NULL));
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &user_input);
    test(user_input, 0x1337d00d);
    return (0);
}