#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
    srand(time(NULL)); //"表示用当前时间作为播种的时间数"

    int secret = rand() % 100 + 1; //随机生成100以内整数
    // printf("电脑想的数字是:%d\n",secret);   // 调试用，正式版藏起来

    int guess = 0;
    int count = 0;
    while (guess != secret){
        printf("猜一个 1~100 的数字:");
        scanf("%d",&guess);
        count++;
        if (guess > secret){
            printf("猜大了\n");
        }else if (guess < secret){
            printf("猜小了\n");
        }else{
            printf("猜对了\n");
        }
    }
    printf("你总共猜了 %d 次\n", count);
    return 0;
}

