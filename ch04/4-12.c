#include "apue.h"
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

/* 
 * this program get first argument file name,
 * second argument changing time (atime or mtime) to now.
 */
int main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec timespecs[2];
    struct timeval timevals[2];

    if (stat(argv[1], &statbuf) < 0)
    { /* fetch current times */
        err_ret("%s: stat error", argv[1]);
    }

    timespecs[0] = statbuf.st_atim;
    timespecs[1] = statbuf.st_mtim;

    if (!argv[2])
    {
        err_sys("no argument");
    }
    else if (strcmp(argv[2], "atime"))
    {
        gettimeofday(&timevals[0], NULL);
        timevals[1].tv_sec = timespecs[1].tv_sec;
        timevals[1].tv_usec = timespecs[1].tv_nsec / 1000;
        if (utimes(argv[1], timevals) < 0)
            err_ret("%s: utimes error", argv[1]);
    }
    else if (strcmp(argv[2], "mtime"))
    {
        timevals[0].tv_sec = timespecs[0].tv_sec;
        timevals[0].tv_usec = timespecs[0].tv_nsec / 1000;
        gettimeofday(&timevals[1], NULL);
        if (utimes(argv[1], timevals) < 0)
            err_ret("%s: utimes error", argv[1]);
    }
    else
    {
        err_sys("%s: argument error", argv[2]);
    }

    exit(0);
}