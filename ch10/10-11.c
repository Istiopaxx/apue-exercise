#include "apue.h"
#include <sys/resource.h>

#define BUFFSIZE 100

void signal_handle(int);

int main(void)
{
    int n, cnt;
    char buf[BUFFSIZE];
    struct rlimit rlmt;
    rlmt.rlim_cur = 1024;
    rlmt.rlim_max = 8096;

    if (setrlimit(RLIMIT_FSIZE, &rlmt) < 0)
        err_sys("setrlimit error");

    if (signal_intr(SIGXFSZ, signal_handle) == SIG_ERR)
        err_sys("signal(SIGXFSZ) error");

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if ((cnt = write(STDOUT_FILENO, buf, n)) != n)
            fprintf(stderr, "%d bytes is written and uncompleted.\n", cnt);

    if (n < 0)
        err_sys("read error");

    exit(0);
}

void signal_handle(int signo)
{
    fprintf(stderr, "SIGXFSZ CATCH\n");
}
