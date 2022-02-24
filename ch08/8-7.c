#include "apue.h"
#include <dirent.h>
#include <fcntl.h>

int main(void)
{
    int fd, fd_flag;
    DIR *dirp;

    if ((dirp = opendir("/")) == NULL)
        err_sys("opendir error");
    if ((fd = dirfd(dirp)) < 0)
        err_sys("dirfd error");
    if ((fd_flag = fcntl(fd, F_GETFD)) < 0)
        err_sys("fcntl error");
    printf("fd_flag of root directory stream(by opendir) is\t\t : %d\t", fd_flag);
    if (fd_flag)
        printf(" -> FD_CLOEXEC\n");
    else
        printf(" -> not set at all\n");
    
    if ((fd = open("/", O_RDONLY)) < 0)
        err_sys("open error");
    if ((fd_flag = fcntl(fd, F_GETFD)) < 0)
        err_sys("fcntl error");
    printf("fd_flag of root directory file descriptor(by open) is\t : %d\t", fd_flag);
    if (fd_flag)
        printf(" -> FD_CLOEXEC\n");
    else
        printf(" -> not set at all\n");

    exit(0);
}