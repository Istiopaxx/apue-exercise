#include "apue.h"


int main()
{
    long *lngarray = (long *)calloc(10, sizeof(long));
    long **lngptraray = (long **)calloc(10, sizeof(long *));
    
    int i;
    for(i = 0; i < 10; i++)
        printf("%ld ", lngarray[i]);
    printf("\n");
    for(i = 0; i < 10; i++)
        printf("%p ", lngptraray[i]);
    printf("\n");

    exit(0);
}
