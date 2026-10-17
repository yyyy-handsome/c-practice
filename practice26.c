#include <stdio.h>

int main(void)
{
    int a[5];              /* 5 个格子，下标是 0 ~ 4 */
    int n = 5;             /* 一共几个数，后面的循环都靠它，不写死 */
    int i, j, t;           /* i: 第几轮  j: 比到第几格  t: 交换用的临时杯子 */

    printf("Please input 5 numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);          /* 读进数组元素要取地址，所以写 &a[i] */
    }

    printf("Before: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    /* 冒泡排序：只比较相邻的两个，左边比右边大就交换 */
    for (i = 0; i < n - 1; i++) {
        /* 每轮结束最右边就多排好一个，所以这一轮少比 i 次 */
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]){      /* 左边比右边大，顺序不对 */
                t = a[j];            /* 先把左边存进临时杯子 */
                a[j] = a[j+1];       /* 把右边搬到左边 */
                a[j+1] = t;          /* 临时杯子里的放回右边 */
            }
        }
    }

    printf("After: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}