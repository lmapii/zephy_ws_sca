/*
 * We're perfectly aware that the `zephyr/kernel.h` is not needed by this unit.
 * This include has been added for demonstration purposes since some static
 * analysis tools, e.g., `cppcheck` currently struggle with `zephyr/kernel.h`,
 * resulting in incomplete analysis reports.
 *
 * See https://github.com/zephyrproject-rtos/zephyr/issues/68946
 */
#include <zephyr/kernel.h>

int foo(void)
{
    char a[10];
    a[10] = 0 / 0;
    return 0;
}
