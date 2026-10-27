#include <stdio.h>

/* 第 14 题（教材 108 页）

   哥德巴赫猜想：任何大于 4 的偶数都能写成两个素数之和。
   对 6 到 5000 的每个偶数都验证一遍。 */

/* 判断 n 是不是素数：是返回 1，不是返回 0 */
int isPrime(int n)
{
    int i;

    if (n < 2) return 0;            /* 0 和 1 都不是素数 */

    /* 只需试到平方根：合数一定有一个因子不超过 sqrt(n)。
       写成 i * i <= n 比调用 sqrt(n) 更安全，也不用引入 math.h */
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;   /* 找到因子，说明不是素数 */
    }
    return 1;
}

int main(void)
{
    int n, p;
    int ok;

    for (n = 6; n <= 5000; n += 2) {    /* 只处理偶数 */
        ok = 0;

        /* 试所有可能的第一个素数 p，另一个加数就是 n - p */
        for (p = 2; p <= n / 2; p++) {
            if (isPrime(p) && isPrime(n - p)) {
                ok = 1;
                break;                  /* 找到一对就够了，不用继续 */
            }
        }

        if (!ok) {
            printf("%d failed\n", n);   /* 理论上不会执行到这里 */
            return 1;
        }
    }

    printf("all even numbers from 6 to 5000 verified\n");
    return 0;
}