#include <zephyr/kernel.h>

int foo_fn(void)
{
    char a[10];
    a[10] = 0 / 0;
    return 0;
}
