#include <stdlib.h>

int baz(int arg)
{
    char *a = malloc(10);
    a[arg]  = 0;
    return 0;
}
