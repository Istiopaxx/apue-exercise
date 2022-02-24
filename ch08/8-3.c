#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    siginfo_t *infobuf = (siginfo_t *) calloc(1, sizeof(siginfo_t));
    int status;

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0) /* child */
        exit(7);
    if (waitid(P_PID, pid, infobuf, WEXITED) < 0) /* wait for child */
        err_sys("wait error");
    printf("normal termination, exit status = %d\n",
           infobuf->si_status); /* and print its info */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)                            /* child */
        abort();                                  /* generates SIGABRT */
    if (waitid(P_PID, pid, infobuf, WEXITED) < 0) /* wait for child */
        err_sys("wait error");
    printf("abnormal termination, signal number = %d\n",
           infobuf->si_status); /* and print its info */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)                            /* child */
        status /= 0;                              /* divide by 0 generates SIGFPE */
    if (waitid(P_PID, pid, infobuf, WEXITED) < 0) /* wait for child */
        err_sys("wait error");
    printf("abnormal termination, signal number = %d\n",
           infobuf->si_status); /* and print its info */

    exit(0);
}