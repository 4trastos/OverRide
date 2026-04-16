#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char    buffer_username[100];   // [rbp-0x70], fgets lee 0x64=100 bytes
    char    buffer_file[41];        // [rbp-0xa0], fread lee 0x29=41 bytes
    char    buffer_password[100];   // [rbp-0x110], fgets lee 0x64=100 bytes
    int     bytes_read = 0;         // [rbp-0xc]
    FILE    *fp = NULL;             // [rbp-0x8]

    memset(buffer_username, 0, 96);
    memset(buffer_file, 0, 40);
    memset(buffer_password, 0, 96);

    fp = fopen("/home/users/level03/.pass", "r");
    if (!fp)
    {
        fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
        exit(1);
    }
    bytes_read = fread(buffer_file, 1, 41, fp);
    buffer_file[strcspn(buffer_file, "\n")] = '\0';
    if (bytes_read != 41)
    {
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        exit(1);
    }
    fclose(fp);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");
    fgets(buffer_username, 100, stdin);
    buffer_username[strcspn(buffer_username, "\n")] = '\0';
    printf("--[ Password: ");
    fgets(buffer_password, 100, stdin);
    buffer_password[strcspn(buffer_password, "\n")] = '\0';
    puts("*****************************************");
    if (strncmp(buffer_file, buffer_password, 41) != 0)
    {
        printf(buffer_username);
        puts(" does not have access!");
        exit(1);
    }
    printf("Greetings, %s!\n", buffer_username);
    system("/bin/sh");
    return (0);
}