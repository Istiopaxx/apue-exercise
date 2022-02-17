#include "apue.h"

int f1(int);

int main(void)
{
    int a, b;

    a = 0;
    b = f1(a);
    printf("b is %d when a is 0\n", b);

    a = 5;
    b = f1(a);
    printf("b is %d when a is 5\n", b);


    exit(0);
}

int f1(int val)
{
    int num = 0;
    int *ptr = &num;

    if (val == 0) {
        int val;
        val = 5;
        ptr = &val;
    }

    return (*ptr + 1);
}