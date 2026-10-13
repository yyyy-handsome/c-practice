#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* 玩一局。参数 secret 是本局答案。返回 1 = 猜对了，0 = 次数用完 */
int playOneRound(int secret){
    int guess = 0;
    int count = 0;

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
        return 1;
    }else{
        printf("七次机会用完了，答案是 %d\n", secret);
        return 0;
    }
}


int main(void){
    srand(time(NULL));                 // 播种：整场游戏只做一次

    int again = 1;                     // 跨局记住要不要继续
    int totalGames = 0;                // 一共玩了多少局（要跨局累计）
    int wins = 0;                      // 赢了多少局

    while (again == 1) {

        int secret = rand() % 100 + 1; // 每局换一个新答案
        totalGames++;

        int result = playOneRound(secret);
        if (result == 1) {
            wins++;
        }

        printf("再来一局输入 1，退出输入 0：");
        scanf("%d", &again);
    }

    printf("总共玩了 %d 局，赢了 %d 局\n", totalGames, wins);
    printf("胜率为 %.2f%%\n", wins * 100.0 / totalGames);
    printf("游戏结束，再见！\n");
    return 0;
}
