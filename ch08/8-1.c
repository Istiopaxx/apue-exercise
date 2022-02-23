#include "apue.h"
int globvar = 6; /* external variable in initialized data */

void my_exit(int);

int main(void)
{
    int var, ret; /* automatic variable on the stack */
    pid_t pid;
    FILE *fp;

    var = 88;
    printf("before vfork\n"); /* we don’t flush stdio */
    if ((pid = vfork()) < 0)
    {
        err_sys("vfork error");
    }
    else if (pid == 0)
    {              /* child */
        globvar++; /* modify parent’s variables */
        var++;
        my_exit(1); /* child terminates */
    }
    /* parent continues here */
    ret = printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    if ((fp = fopen("./8-1.out", "w")) == NULL)
        err_sys("fopen error");
    fprintf(fp, "the return value of printf() : %d\n", ret);

    exit(0);
}

void my_exit(int status) {
    fflush(stdin);
    fflush(stdout);
    fflush(stderr);

    fclose(stdin);
    fclose(stdout);
    fclose(stderr);

    exit(status);
}
