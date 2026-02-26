#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char a_user_name[256];

int verify_user_pass(char *password)
{
    
}

int verify_user_name(void)
{
    puts("verifying username....\n");
    if (strncmp("dat_wil", a_user_name, 7) != 0)
        return (1);
    return (0);
}

int main(void)
{
    FILE    *file;

    memset(file, 0, 64);

    puts("********* ADMIN LOGIN PROMPT *********\n");
    printf("Enter Username: \n");

    fgets(a_user_name, 256, file);
    if (verify_user_name() == 0)
    {
        puts("Enter Password: ");
        fgets(a_user_name, 100, file);
        if (verify_user_pass(a_user_name) == 0)
        {

        }
        else
        {
            printf("nope, incorrect username...\n");
            return (1);
        }
    }
    else
    {
        printf("nope, incorrect username...\n");
        return (1);
    }
    return (0);
}