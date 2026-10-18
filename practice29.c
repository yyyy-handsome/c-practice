#include <stdio.h>

/* p  vs  *p
   p   是纸条上的门牌号（地址）。p = &a 表示"以后去 a 这一家"。
   *p  是那家房间里的东西（值）。  *p = 5 表示"把房间里的内容换成 5"。
   判断口诀：等号左边写 p 就换目标，写 *p 就改内容。 */

int main(void)
{
    int a;
    int *p;                 /* p 是"写着门牌号的纸条"，类型是 int* */

    printf("input a number: ");
    scanf("%d", &a);        /* 把 a 的地址交给 scanf，它才能写进 a */

    printf("before: %d\n", a);

    p = &a;                 /* 左边是 p：在纸条上写 a 的门牌号，改"指向谁" */

    *p = *p * 2;            /* 左边是 *p：进房间，把里面的值翻倍再放回去 */

    printf("after: %d\n", a);

    return 0;
}