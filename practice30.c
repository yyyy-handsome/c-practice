#include <stdio.h>

/* p  vs  *p
   p   是纸条上的门牌号（地址）。p = &a 表示"以后去 a 这一家"。
   *p  是那家房间里的东西（值）。  *p = 5 表示"把房间里的内容换成 5"。
   判断口诀：等号左边写 p 就换目标，写 *p 就改内容。 */

void swap(int *pa, int *pb)   /* 收到的是地址，不是数值的复印件 */
{
    int t = *pa;              /* 进 pa 的房间，把值拿出来存进临时变量 */
    *pa = *pb;                /* 把 pb 房间的值抄到 pa 房间 */
    *pb = t;                  /* 把临时变量放回 pb 房间 */
}

int main(void)
{
    int x, y;

    printf("please input two number:");
    scanf("%d %d", &x, &y);

    swap(&x, &y);             /* 传地址，函数才能改到原件 */
    printf("x = %d y = %d\n", x, y);

    return 0;
}