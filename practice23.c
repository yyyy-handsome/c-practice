#include <stdio.h>

void printChar(int n, char ch){
    for(int i=0;i<n;i++){
        printf("%c",ch);
    }
    printf("\n");
}

void printTriangle(int n, char ch){
    for(int i=1;i<=n;i++){
        printChar(i, ch);
    }
}

int main(void){
    int n;
    char ch;
    scanf("%d %c",&n,&ch);
    
    printChar(n,ch);
    printf("\n");
    printTriangle(n,ch);
    return 0;
}