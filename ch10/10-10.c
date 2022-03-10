#include "apue.h"
#include <time.h>

int main(void)
{
    int cnt;
    time_t t;
    struct tm *tmp;
    for (cnt = 1; 1; cnt++)
    {
        sleep(60);
        if (cnt % 5 == 0)
        {
            time(&t);
            tmp = localtime(&t);
            printf("now cnt is : %d and tm_sec is %d\n", cnt, tmp->tm_sec);
        }
    }

    exit(0);
}