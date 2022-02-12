#include "apue.h"
#include <time.h>

int main(void)
{
    time_t p;
    struct tm *tmp;
    char buf[128];

    time(&p);
    tmp = localtime(&p);
    if (strftime(buf, 128, "%a %b %d %H:%M:%S %Z %Y", tmp) == 0)
        err_sys("strftime_l error");

    printf("%s\n", buf);

    exit(0);
}