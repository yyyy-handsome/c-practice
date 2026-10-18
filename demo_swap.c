#include <stdio.h>

void swapWrong(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

void swapRight(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

int main(void)
{
    int x = 3, y = 7;

    printf("start:  x=%d y=%d\n", x, y);

    swapWrong(x, y);
    printf("after swapWrong(x, y):      x=%d y=%d\n", x, y);

    swapRight(&x, &y);
    printf("after swapRight(&x, &y):    x=%d y=%d\n", x, y);

    return 0;
}