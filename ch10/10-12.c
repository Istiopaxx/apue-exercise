#include "apue.h"
#include <string.h>

#define BUFSIZE 250000000

void signal_alrm(int);

int main(void)
{
    static int buf[BUFSIZE];
    FILE *fp;

    memset(buf, -1, sizeof(buf));

    if (signal(SIGALRM, signal_alrm) == SIG_ERR)
        err_sys("signal(SIGALRM) error");

    if ((fp = fopen("./10-12-out.txt", "w+")) == NULL)
        err_sys("fopen error");

    alarm(1);
    
    printf("fwrite start\n");
    if (fwrite(buf, sizeof(int), BUFSIZE, fp) != BUFSIZE)
        err_sys("fwrite error");
    printf("fwrite end\n");

    exit(0);
}

void signal_alrm(int signo)
{
    printf("%d signal is caught\n", signo);
}