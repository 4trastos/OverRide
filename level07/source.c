#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int store_number(unsigned int *data)
{
    unsigned int    number;     // [ebp-0x10]
    unsigned int    index;      // [ebp-0xc]

    printf(" Number: ");
    number = get_unum();
    printf(" Index: ");
    index = get_unum();
    if (index % 3 == 0 || (number >> 24) == 0xb7)
    {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return (1);
    }
    data[index] = number;
    return (0);
}

int read_number(unsigned int *data)
{
    unsigned int    index;      // [ebp-0xc]

    printf(" Index: ");
    index = get_unum();
    printf(" Number at data[%u] is %u\n", index, data[index]);
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    unsigned int    data[100];  // [esp+0x24]
    char            cmd[20];    // [esp+0x1b8]
    int             running;    // [esp+0x1b4]

    memset(data, 0, 400);
    while (*argv)
    {
        memset(*argv, 0, strlen(*argv));
        argv++;
    }
    while (*envp)
    {
        memset(*envp, 0, strlen(*envp));
        envp++;
    }
    puts("----[cabecera]----");
    running = 1;
    while (running)
    {
        printf("Input command: ");
        fgets(cmd, 20, stdin);
        cmd[strlen(cmd) - 1] = '\0';
        if (strncmp(cmd, "store", 5) == 0)
            running = store_number(data);
        else if (strncmp(cmd, "read", 4) == 0)
            running = read_number(data);
        else if (strncmp(cmd, "quit", 4) == 0)
            break;
        if (running)
            printf(" Failed to do %s command\n", cmd);
        else
            printf(" Completed %s command successfully\n", cmd);
        memset(cmd, 0, 20);
    }
    return (0);
}