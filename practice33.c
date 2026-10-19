#include <stdio.h>

void findMaxMin(int *a, int n, int *pMax, int *pMin)
{
    /* 四个参数各是什么：
       a    : 数组第一个格子的地址（传数组名时，数组名本身就是首地址）
       n    : 一共有几个数
       pMax : main 里 max 这个变量的地址，相当于"结果盒子的门牌号"
       pMin : main 里 min 这个变量的地址 */

    int *p;         /* p 是遍历用的指针，一会儿要一个格子一个格子往后走 */

    *pMax = *a;     /* *a 是第一个格子的值，*pMax 是 main 里的 max。
                       这句等于：先把第一个数放进最大值盒子 */
    *pMin = *a;     /* 最小值盒子也先放第一个数 */

    /* p = a + 1：让 p 指向第二个格子。
       a 是首地址，a+1 不是"往后 1 个字节"，而是"往后 1 个 int"，
       实际地址会加 4。因为第一个数已经放进盒子了，所以从第二个开始比 */
    for (p = a + 1; p < a + n; p++) {
        /* p < a + n：a+n 是"最后一个格子再往后一格"的地址。
           只要 p 还没走到这里，就说明还没越界 */

        if (*p > *pMax) {   /* *p 是当前格子的值，*pMax 是盒子里现在最大的值 */
            *pMax = *p;     /* 当前这个更大，就把盒子里的内容换成它 */
        }

        if (*p < *pMin) {   /* *pMin 是盒子里现在最小的值 */
            *pMin = *p;     /* 当前这个更小，就换掉 */
        }

        /* p++：走到下一个格子。指向 int 的指针加 1，地址前进 4 字节 */
    }
    /* 这里没有 return，因为结果已经通过 *pMax / *pMin
       写进 main 的 max / min 里了 */
}

int main(void)
{
    int data[7] = {3, 9, -2, 7, 5, 0, 8};

    /* 两个空盒子，先不赋值，等着函数往里面写 */
    int max, min;

    /* 调用时的四个实参：
       data : 数组名本身就是首地址，直接传，不加 &
       7    : 元素个数
       &max : 取 max 的地址。函数收到地址，才能往这个盒子里写
       &min : 同上 */
    findMaxMin(data, 7, &max, &min);

    /* 这里打印的是 max / min（盒子里的值）。
       如果写 &max，打印出来的就是地址，不是你要的结果 */
    printf("max = %d, min = %d\n", max, min);

    return 0;
}