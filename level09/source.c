#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_msg
{
    char            msg[140];   // [rbp-0xc0] a [rbp-0xc0+0x8b]
    char            username[40]; // [rbp-0xc0+0x8c]
    int             len;        // [rbp-0xc]
}   t_msg;

void    secret_backdoor(void)
{
    char    cmd[128];   // [rbp-0x80]

    fgets(cmd, 128, stdin);
    system(cmd);
}

void    set_msg(t_msg *msg)
{
    char    buf[1024];  // [rbp-0x400]

    memset(buf, 0, 1024);
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(buf, 1024, stdin);
    strncpy(msg->msg, buf, msg->len);
}

void    set_username(t_msg *msg)
{
    char    buf[128];   // [rbp-0x90]
    int     i;          // [rbp-0x4]

    memset(buf, 0, 128);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(buf, 128, stdin);
    for (i = 0; i <= 40 && buf[i]; i++)
        msg->username[i] = buf[i];
    printf(">: Welcome, %s", msg->username);
}

void    handle_msg(void)
{
    t_msg   msg;

    memset(msg.username, 0, 40);
    msg.len = 140;
    set_username(&msg);
    set_msg(&msg);
    puts(">: Msg sent!");
}

int main(void)
{
    puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
    handle_msg();
    return (0);
}