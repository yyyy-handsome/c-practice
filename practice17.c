#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    
    int isPrime = 1;
    if (n <= 1){
        isPrime = 0;
    }
    for (int i = 2; i<n; i++){
        if (n%i == 0){
            isPrime = 0;
            break;
        }
    }
    printf("%d\n",isPrime);
    return 0;
}
