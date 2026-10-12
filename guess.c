#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
    srand(time(NULL));                 // 播种：整场游戏只做一次

    int again = 1;                     // 跨局记住要不要继续
    while (again == 1) {

        int secret = rand() % 100 + 1; // 每局换一个新答案
        int guess = 0;                 // 每局重新开始猜
        int count = 0;                 // 每局重新数次数

        while (guess != secret && count < 7){
            printf("猜一个 1~100 的整数：");
            scanf("%d", &guess);
            count++;

            if (guess > secret){
                printf("猜大了\n");
            }else if (guess < secret){
                printf("猜小了\n");
            }else{
                printf("猜对了\n");
            }
        }

        if (guess == secret){
            printf("恭喜你猜对了，用了 %d 次\n", count);
        }else{
            printf("七次机会用完了，答案是 %d\n", secret);
        }

        printf("再来一局输入 1，退出输入 0：");
        scanf("%d", &again);
    }

    printf("游戏结束，再见！\n");
    return 0;
}