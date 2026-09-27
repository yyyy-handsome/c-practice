#include <stdio.h>

int main(void){

    int x;
    int sum=0;

    scanf("%d",&x);

    while(x !=0){
        sum=sum+x;
        scanf("%d",&x);
    }
    printf("输入的数字之和是:%d\n",sum);
    return 0;
}