#include "apue.h"
#include <limits.h>
#include <time.h>

int main(void)
{
    time_t t;
    struct tm *tmp;
    char buf[65535];
    int f1, f2;
    long int jump;

    t = (time_t)0;
    tmp = localtime(&t);

    f1 = 0;
    f2 = 0;
    jump = 1;
    while (jump != 0)
    {
        t += (time_t)jump;
        if ((tmp = localtime(&t)) == NULL)
        {
            t -= (time_t)jump;
            jump /= 2;
        }
        else
            jump *= 2;
        printf("t : %ld || jump : %ld\n", t, jump);
    }

    tmp = localtime(&t);
    printf("\n\nmost possible big time_t which can be called with localtime() : ");
    printf("%d:%d:%d %d-%d-%d\n",
           tmp->tm_hour,
           tmp->tm_min,
           tmp->tm_sec,
           tmp->tm_year,
           tmp->tm_mon,
           tmp->tm_mday);

    t = (time_t)9223372036854775807;
    printf("before overflow time_t : %ld\n", t);
    t += (time_t)1;
    printf("after  overflow time_t : %ld\n", t);

    exit(0);
}
