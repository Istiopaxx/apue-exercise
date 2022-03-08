#include "apue.h"

int main(void)
{
    FILE *fp;
    pid_t pid;
    int buf = 0;

    if ((fp = fopen("./10-06-out.txt", "w+")) == NULL)
        err_sys("fopen error");
    fprintf(fp, "0");
    fclose(fp);

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
    {   /* child */
        while(buf < 100)
        {
            WAIT_PARENT(); /* parent go first */
            if ((fp = fopen("./10-06-out.txt", "w+")) == NULL)
                err_sys("fopen error");
            fscanf(fp, "%d", &buf);
            buf++;
            if (fseek(fp, 0, SEEK_SET) < 0)
                err_sys("fseek error");
            fprintf(fp, "%d", buf);
            printf("child increase the counter to : %d\n", buf);
            fclose(fp);
            TELL_PARENT(getppid()); /* let parent to go */
        }
    }
    else
    {   /* parent */
        while(buf < 100)
        {
            if ((fp = fopen("./10-06-out.txt", "w+")) == NULL)
                err_sys("fopen error");
            fscanf(fp, "%d", &buf);
            buf++;
            if (fseek(fp, 0, SEEK_SET) < 0)
                err_sys("fseek error");
            fprintf(fp, "%d", buf);
            printf("parent increase the counter to : %d\n", buf);
            fclose(fp);
            TELL_CHILD(pid); /* let child to go */
            WAIT_CHILD();    /* wait child to finish */
        }
    }

    exit(0);
}