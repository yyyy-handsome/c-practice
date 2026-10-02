#include <stdio.h>

int main(void){
    int n;
    printf("请输入数字的个数:\n");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        sum = sum + x;
    }

    printf("这 %d 个数的和是 %d\n", n, sum);
    return 0;
}