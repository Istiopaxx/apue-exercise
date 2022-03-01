#include "apue.h"
#include "stdio.h"
#include "unistd.h"

int myfunc(void);
pid_t pid;

int myfunc(void) {
    int int_var = 7;

    if ((pid = vfork()) < 0)
    {
        // err_sys("vfork error");
        printf("vfork error");
        _exit(0);
    }

    else if (pid == 0)
    {
        printf("child start, pid = %d\n", getpid());
    }
    else
    {
        printf("parent start, pid = %d\n", getpid());
    }
    return 8;
}

int main(void) 
{
    int ret;
    ret = myfunc();
    printf("after my func, pid = %d\n", pid);

    exit(0);
}
