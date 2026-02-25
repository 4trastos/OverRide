#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int input;                      // Esta es la variable en [esp+0x1c]

    puts("***********************************");
    puts("* 	       -Level00 -		    *");
    puts("***********************************");
    printf("Password:");

    if (__isoc99_scanf("%d", &input) != 1)
        puts("\nInvalid Password!");
    
    if (input == 5276)              // <+83>:	cmp    eax,0x149c
    {
        puts("\nAuthenticated!");
        system("/bin/sh");
    }
    else
        puts("\nInvalid Password!");
    
    return(0);
}