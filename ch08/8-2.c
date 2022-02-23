#include "apue.h"

int myfunc(void);

int myfunc(void) {
    pid_t pid;
    int int_var;

    if ((pid = vfork()) < 0)
        err_sys("vfork error");
    else if (pid == 0)
    {   /* child */
        int_var = 55;
        return 1;
    }
    else
    {   /* parent */
        int_var = 66;
    }
    return 0;
}

int main(void) 
{
    int ret;
    ret = myfunc();

    exit(0);
}
