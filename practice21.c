#include <stdio.h>

int max2(int a, int b){
    return a > b? a : b;  //>是取大值，反之
}

int main(void){
    int x, y, z;
    scanf("%d %d %d",&x,&y,&z);

    printf("最大值是:%d\n",max2(max2(x, y),z));
    return 0;
}