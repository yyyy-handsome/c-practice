#include <stdio.h>

int main(void){
    /*int n;
    printf("请输入一个数字：\n");
    scanf("%d",&n);
    if (n%2==0){
        printf("%d是偶数\n",n);
    }else{
        printf("%d是奇数\n",n);
    }*/
    int score;
    printf("请输入成绩\n");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("成绩无效\n");
    } else if (score >= 90) {
        printf("成绩优秀\n");
    } else if (score >= 80) {
        printf("成绩良好\n");
    } else if (score >= 60) {
        printf("成绩及格\n");
    } else {
        printf("成绩不及格\n");
    }

    return 0;
}