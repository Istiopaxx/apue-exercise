#include "apue.h"

int main(void)
{
    int out, i;
    out = printf("", i);
    printf("return value of first printf() call : %d\n", out);

    exit(0);
}