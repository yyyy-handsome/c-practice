#include <stdio.h>

int main(void){
    int foot,inch;
    printf("请输入英尺和英寸：\n");
    scanf("%d %d",&foot,&inch);
    printf("身高是多少米: %.2f\n",(foot+inch/12.0)*0.3048);
    return 0;
}