#include "apue.h"

static char buf[4096];

int main()
{
    FILE *fp = fopen("/etc/shadow", "r");

    while (fgets(buf, 4096, fp) != NULL)
    {
        fputs(buf, stdout);
    }

    exit(0);
}

