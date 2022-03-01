#include "apue.h"
#include <sys/wait.h>
#include <fcntl.h>

int main(void)
{
    pid_t pid;
    int status, fd;

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
    {
        printf("child\n");
        if (setsid() < 0)
            err_sys("setsid error");
        printf("pid of child : %d\npgid of child : %d\n", getpid(), getpgrp());
        if ((fd = open("/dev/tty", O_RDWR)) < 0)
            err_sys("open error: no control terminal");
    }
    else
    {
        if ((pid = wait(&status)) < 0)
            err_sys("waitpid error");
    }

    exit(0);
}
