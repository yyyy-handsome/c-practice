#include <stdio.h>

/* p  vs  *p
   p   是纸条上的门牌号（地址）。p = &a 表示"以后去 a 这一家"。
   *p  是那家房间里的东西（值）。  *p = 5 表示"把房间里的内容换成 5"。
   判断口诀：等号左边写 p 就换目标，写 *p 就改内容。 */

int sumByPointer(int *a, int n)   /* a 是数组首地址，n 是元素个数 */
{
    int sum = 0;
    int *p;

    for (p = a; p < a + n; p++) { /* p 从第一格走到最后一格的下一格 */
        sum = sum + *p;           /* *p 取出当前格子的值，累加到 sum */
    }
    return sum;
}

int maxByPointer(int *a, int n)
{
    int max = *a;                    /* 先拿第一格当擂主 */
    int *p;

    for (p = a + 1; p < a + n; p++) { /* 从第二格开始依次挑战 */
        if (*p > max) {               /* 挑战者更大 */
            max = *p;                 /* 换擂主 */
        }
    }
    return max;
}

int main(void)
{
    int arr[5];                       /* 5 个格子，下标 0 ~ 4 */
    int i;

    printf("please input five number: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);         /* 数组元素要取地址 */
    }

    printf("sum = %d\n", sumByPointer(arr, 5));   /* 调用只写数组名 + 长度 */
    printf("max = %d\n", maxByPointer(arr, 5));

    return 0;
}