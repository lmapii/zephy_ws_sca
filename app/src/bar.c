/*
 * In contrast to `foo.c` this file does not include
 * the sometimes problematic `<zephyr/kernel.h>`.
 */
// #include <zephyr/kernel.h>

int bar(int arg)
{
    char a[10];
    a[10] = 0 / 0;
    return 0;
}
