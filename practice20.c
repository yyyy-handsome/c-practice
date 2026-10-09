#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d",&a,&b);

    while (b != 0){
        int r = a % b;   //余数
        a = b;
        b = r;
    }
    printf("%d\n",a);
    return 0;
}