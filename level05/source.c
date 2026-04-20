#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char    buf[100];       // [esp+0x28]
    int     i;              // [esp+0x8c]

    fgets(buf, 100, stdin);
    for (i = 0; i < strlen(buf); i++)
    {
        if (buf[i] > 0x40 && buf[i] <= 0x5a)
            buf[i] ^= 0x20;
    }
    printf(buf);
    exit(0);
}