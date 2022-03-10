#include "apue.h"
#include <time.h>

int main(void)
{
    FILE *fp;
    pid_t pid;
    int buf = 0;
    struct timespec tm;
    tm.tv_sec = 0;
    tm.tv_nsec = 3 * 100 * 1000 * 1000;

    if ((fp = fopen("./10-06-out.txt", "w+")) == NULL)
        err_sys("fopen error");
    fprintf(fp, "0");
    fflush(fp);
    TELL_WAIT();

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
    {   /* child */
        while(buf < 100)
        {
            WAIT_PARENT(); /* parent go first */
            nanosleep(&tm, NULL);
            if (fseek(fp, 0, SEEK_SET) < 0)
                err_sys("fseek error");
            fscanf(fp, "%d", &buf);
            buf++;
            if (fseek(fp, 0, SEEK_SET) < 0)
                err_sys("fseek error");
            fprintf(fp, "%d", buf);
            fflush(fp);
            printf("child increase the counter to : %d\n", buf);
            TELL_PARENT(getppid()); /* let parent to go */
        }
    }
    else
    {   /* parent */
        while(buf < 100)
        {
            nanosleep(&tm, NULL);
            if (fseek(fp, 0, SEEK_SET) < 0)
                err_sys("fseek error");
            fscanf(fp, "%d", &buf);
            buf++;
            if (fseek(fp, 0, SEEK_SET) < 0)
                err_sys("fseek error");
            fprintf(fp, "%d", buf);
            fflush(fp);
            printf("parent increase the counter to : %d\n", buf);
            TELL_CHILD(pid); /* let child to go */
            WAIT_CHILD();    /* wait child to finish */
        }
    }

    exit(0);
}