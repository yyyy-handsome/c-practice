#include <stdio.h>

int main(void)
{
    int x = 42;
    int *p = &x;

    printf("x   = %d\n", x);
    printf("&x  = %p\n", (void *)&x);
    printf("p   = %p\n", (void *)p);
    printf("*p  = %d\n", *p);
    printf("sizeof(p) = %d\n", (int)sizeof(p));

    *p = 99;
    printf("after *p = 99, x = %d\n", x);

    return 0;
}