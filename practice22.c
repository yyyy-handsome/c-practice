#include <stdio.h>

void printStars(int n){
    for(int i=0;i<n;i++){
        printf("*");
    }
    printf("\n");
}

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printStars(i);
    }
    return 0;
}