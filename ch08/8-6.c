#include "apue.h"
#include "string.h"

int main(void)
{
    pid_t pid;
    int var;
    char *cmd_str, *pid_str;

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)  /* child */
        exit(0);
    else /* parent */
    {
        sprintf(pid_str, "%d", pid);
        cmd_str = malloc(sizeof(char) * 20);
        strcpy(cmd_str, "ps l ");
        sleep(1);
        if (system(strcat(cmd_str, pid_str)) < 0)
            err_sys("systme(ps) error");
    }

    exit(0);
}