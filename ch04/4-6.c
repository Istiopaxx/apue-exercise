#include "apue.h"
#include <fcntl.h>

#define BUFFSIZE 4096

int
main(int argc, char *argv[])
{
    int n, origin_fd, dest_fd, i;
    char buf[BUFFSIZE];

    origin_fd = open(argv[1], O_RDONLY);
    if (argv[2])
        dest_fd = creat(argv[2], (S_IRUSR | S_IWUSR));
    else {
        dest_fd = creat(strcat(argv[1], ".copy"), (S_IRUSR | S_IWUSR));
    }

    while ((n = read(origin_fd, buf, BUFFSIZE)) > 0) {
        n = 0;
        for (i = 0; i < BUFFSIZE; i++) {
            if (buf[i] != '\0') {
                buf[n] = buf[i];
                n++;
            }
        }
        if (write(dest_fd, buf, n) != n)
            err_sys("write error");
    }
    if (n < 0)
        err_sys("read error");
    
    exit(0);
}