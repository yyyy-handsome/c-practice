#include <stdio.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int i;

    for (i = 0; i < 5; i++) {
        printf("a[%d] = %d ,  *(a+%d) = %d ,  地址 %p / %p\n",
               i, a[i], i, *(a + i), (void *)&a[i], (void *)(a + i));
    }
    return 0;
}