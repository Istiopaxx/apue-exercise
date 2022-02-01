#include "apue.h"

void setbuf(FILE *restrict, char *restrict);
void pr_stdio(const char *, FILE *);
int is_unbuffered(FILE *);
int is_linebuffered(FILE *);
int buffer_size(FILE *);

int main(void)
{
    FILE *fp;
    char buf1[BUFSIZ];
    char buf2[BUFSIZ];

    if ((fp = fopen("/etc/passwd", "r")) == NULL)
        err_sys("fopen error");
    setbuf(fp, NULL);
    if (getc(fp) == EOF)
        err_sys("getc error");
    pr_stdio("/etc/passwd", fp);

    if ((fp = fopen("/etc/group", "r")) == NULL)
        err_sys("fopen error");
    setbuf(fp, buf1);
    if (getc(fp) == EOF)
        err_sys("getc error");
    pr_stdio("/etc/group", fp);

    setbuf(stderr, buf2);
    fputs("one line to standard error\n", stderr);
    pr_stdio("stderr", stderr);

    exit(0);
}

void setbuf(FILE *restrict fp, char *restrict buf)
{
    if (buf == NULL)
    {
        if (setvbuf(fp, NULL, _IONBF, 0) != 0)
            err_sys("setvbuf error");
    }
    else
    {
        printf("bufsiz: %d\n", BUFSIZ);
        if (setvbuf(fp, NULL, _IOFBF, BUFSIZ) != 0)
            err_sys("setvbuf error");
    }
}

void pr_stdio(const char *name, FILE *fp)
{
    printf("stream = %s, ", name);
    if (is_unbuffered(fp))
        printf("unbuffered");
    else if (is_linebuffered(fp))
        printf("line buffered");
    else /* if neither of above */
        printf("fully buffered");
    printf(", buffer size = %d\n", buffer_size(fp));
}

/*
* The following is nonportable.
*/
#if defined(_IONBF)
int is_unbuffered(FILE *fp)
{
    return (fp->_flags & _IONBF);
}
int is_linebuffered(FILE *fp)
{
    return (fp->_flags & _IOLBF);
}
int buffer_size(FILE *fp)
{
    return (fp->_IO_buf_end - fp->_IO_buf_base); /* just a guess */
}
#else
#error unknown stdio implementation!
#endif
