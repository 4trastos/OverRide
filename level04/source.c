#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>
#include <signal.h>

int main(void)
{
    pid_t   pid;                // [esp+0xac]
    pid_t   wait_pid;           // [esp+0xa8]
    int     status;             // [esp+0x1c]
    char    user_input[128];    // [esp+0x20]

    pid = fork();
    memset(user_input, 0, 128);
    if (pid == 0)
    {
        prctl(PR_SET_PDEATHSIG, 1);
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        puts("Give me some shellcode, k");
        gets(user_input);
    }
    else
    {
        wait(&status);
        if (WIFSIGNALED(status))
        {
            wait_pid = ptrace(PTRACE_PEEKUSER, pid, 44, 0);
            if (wait_pid == 0xb)
            {
                puts("no exec() for you");
                kill(pid, SIGKILL);
            }
        }
        else
            puts("child is exiting...");
    }
    return (0);
}