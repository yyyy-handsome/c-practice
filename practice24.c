#include <stdio.h>

int main(void){
    int s[5];
    int sum = 0;
    
    printf("请输入五个数:\n");
    for(int i=0;i<5;i++){
        scanf("%d",&s[i]);
    }

    printf("你输入的是:");
    for(int i=0;i<5;i++){
        printf("%d ",s[i]);
    }
    printf("\n");

    printf("倒序是:");
    for(int i=4;i>=0;i--){
        printf("%d ",s[i]);
    }
    printf("\n");

    for(int i=0;i<5;i++){
        sum += s[i];
    }

    printf("五个数的和为: %d\n", sum);
    printf("average:%.2f\n",sum/5.0);
    return 0;
}