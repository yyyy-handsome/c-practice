#include <stdio.h>

/* 求平均分，返回 double
   参数：a 是数组首地址，n 是元素个数 */
double average(int *a, int n)  //n是元素个数
{
    int sum = 0;        /* 累加器必须从 0 开始，否则是随机值 */
    int i;

    for (i = 0; i < n; i++) {
        sum = sum + a[i];      /* a[i] 等价于 *(a + i) */
    }

    /* sum / n 是两个 int 相除，小数部分会被丢掉（478/6 会得到 79）
       sum * 1.0 先把整数变成小数，再做除法，结果才是 79.666... */
    return sum * 1.0 / n;
}

/* 统计有多少人高于平均分
   参数 avg 是普通 double，不是指针：
   因为函数只需要"读"它，不需要改它，所以传值就够了 */
int countAboveAverage(int *a, int n, double avg)
{
    int i;
    int count = 0;      /* 计数器，同样必须从 0 开始 */

    for (i = 0; i < n; i++) {
        if (a[i] > avg) {      /* 严格大于才算高于平均分 */
            count++;           /* 等价于 count = count + 1 */
        }
    }

    return count;
}

int main(void)
{
    /* 花括号里直接给出 6 个初值，数组长度由编译器数出来是 6 */
    int scores[6] = {90, 75, 60, 88, 95, 70};

    /* 调用 average：数组名 scores 本身就是首地址，直接传；
       6 是元素个数。返回值存进 avg */
    double avg = average(scores, 6);  //average(scores,6)进函数得出来的值赋给avg

    printf("avg = %.2f\n", avg);   /* %.2f 表示保留两位小数 */

    /* 把算好的 avg 再传给第二个函数，避免重复计算平均分 */
    printf("above = %d\n", countAboveAverage(scores, 6, avg));

    return 0;
}