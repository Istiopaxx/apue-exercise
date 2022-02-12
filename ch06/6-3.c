#include "apue.h"
#include <sys/utsname.h>

static struct utsname utsbuf;

int main()
{
    if (uname(&utsbuf) < 0)
        err_sys("uname error");

    printf("sysname\t\t%s\nnodename\t%s\nrelease\t\t%s\nversion\t\t%s\nmachine\t\t%s\n",
            utsbuf.sysname,
            utsbuf.nodename,
            utsbuf.release,
            utsbuf.version,
            utsbuf.machine);
    
    exit(0);
}
