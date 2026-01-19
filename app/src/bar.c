/*
 * In contrast to `foo.c` this include file is analyzed correctly since
 * it doesn't have any (problematic) includes.
 */
// #include <zephyr/kernel.h>

int bar(int arg)
{
    char a[10];
    a[10] = 0 / 0;
    return 0;
}
