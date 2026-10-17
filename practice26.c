#include <stdio.h>

int main(void)
{
    int a[5];
    int n = 5;
    int i, j, t;

    printf("Please input 5 numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Before: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    printf("After: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}