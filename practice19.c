#include <stdio.h>

int main(void){
    int a,b;
    scanf("%d %d",&a,&b);

    for (int i = a; i >= 1; i--){
        if (a % i == 0 && b % i == 0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}