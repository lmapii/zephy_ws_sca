/*
 * We're perfectly aware that the `zephyr/kernel.h` is not needed by this unit.
 * This include has been added for demonstration purposes - `cppcheck` currently
 * doesn't for any unit that includes `zephyr/kernel.h` since in simple words
 * it cannot resolve some macros and _Kconfig_ options.
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
