#include "apue.h"
#include <stdlib.h>
#include <string.h>

int sig2str(int signo, char *str);

int sig2str(int signo, char *str)
{
    strcpy(str, strsignal(signo));
    char *tmp = malloc(sizeof(char) * 40);
    sprintf(tmp, "Unknown signal %d", signo);
    if (!strcmp(str, tmp))
        return -1;
    return 0;
}

static void sig_usr1(int signo)
{
    char *buf;
    buf = malloc(sizeof(char) * 40);
    if (sig2str(signo, buf) < 0)
        err_sys("sig2str failed");
    printf("signal is : %s\n", buf);
}

int main(void) {

    if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
        err_sys("signal error");

    for (;;)
        pause();

    exit(0);
}