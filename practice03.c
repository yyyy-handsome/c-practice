#include <stdio.h>
int main(void){
    int age = 18;
    double height = 1.75;
    char initial ='A';
    printf("年龄 ：%d\n",age);
    printf("身高：%.2f\n",height);
    printf("首字母:%c\n",initial);
    printf("\n");
    int a = 7, b = 3;
    printf("a+b=%d\n",a+b);
    printf("a-b=%d\n",a-b);
    printf("a*b=%d\n",a*b);
    printf("\n");
    int score = 90;
    score = score + 5;
    printf("score=%d\n",score);
    printf("\n");
    double r = 2.5;
    double area = 3.14159*r*r;
    printf("半径为%.2f的圆的面积为%.2f\n",r, area);
    printf("\n");
    int r2 = 2.5;
    printf("r2=%d\n",r2);
    printf("圆的面积为%.2f\n",3.14159*r2*r2);
     return 0;
}