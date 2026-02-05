/*
 * We're perfectly aware that the `zephyr/kernel.h` is not needed by this unit.
 * This include has been added for demonstration purposes and to ensure that
 * static analyzers work even with `<zephyr/kernel.h>` included - which did
 * cause problems in the past.
 */
#include <zephyr/kernel.h>

int foo(void)
{
    char a[10];
    a[10] = 0 / 0;
    return 0;
}
