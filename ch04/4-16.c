#include "apue.h"
#include <sys/stat.h>
#include <limits.h>

#define RWXRXRX (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)

int recursive_path(void);

char *ptr;
size_t size;

int pathsize;

int main(int argc, char *argv[])
{

    if (chdir(argv[1]) < 0)
        err_sys("chdir failed");
    ptr = path_alloc(&size);
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");
    printf("start dir = %s\n", ptr);

    pathsize = strlen(argv[1]);
    recursive_path();

    exit(0);
}

int recursive_path(void)
{

    if (pathsize > PATH_MAX)
        printf("reached to PATH_MAX\n");
    

    if (mkdir("newverylongdirectorynameihopethismakepositiveresult", RWXRXRX) < 0)
    {
        err_sys("mkdir failed");
        return -1;
    }
    if (chdir("./newverylongdirectorynameihopethismakepositiveresult") < 0)
    {
        err_sys("chdir failed");
        return -1;
    }
    pathsize += strlen("newverylongdirectorynameihopethismakepositiveresult");
    recursive_path();

    return 0;
}
