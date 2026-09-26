#include <stdio.h>

int main(void){
    int a,b,c;
    printf("请输入三个数:\n");
    scanf("%d %d %d",&a,&b,&c);
    int max = a;
    if(b>max){
        max = b;
    }
    if(c>max){
        max = c;
    }
    printf("最大值是%d\n",max);
    return 0;
}