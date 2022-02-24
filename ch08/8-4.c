#include "apue.h"

static void charatatime(char *);

int main(void)
{
    pid_t pid;
    TELL_WAIT();
    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0) /* child */
    {
        WAIT_PARENT();                      /* parent goes first */
        charatatime("output from child\n");
        TELL_PARENT(getppid());             /* tell parent we're done */
    }
    else /* parent */
    {
        charatatime("output from parent\n");
        TELL_CHILD(pid);                    /* tell child we're done */
        WAIT_CHILD();                       /* wait for child to finish */
    }
    exit(0);
}

static void charatatime(char *str)
{
    char *ptr;
    int c;
    setbuf(stdout, NULL); /* set unbuffered */
    for (ptr = str; (c = *ptr++) != 0;)
        putc(c, stdout);
}