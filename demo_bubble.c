#include <stdio.h>

int main(void)
{
    int a[5] = {5, 2, 9, 1, 7};
    int n = 5;
    int i, j, t;

    printf("Before: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    for (i = 0; i < n - 1; i++) {
        printf("Round %d: ", i + 1);
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                printf("[swap a[%d] and a[%d]] ", j, j + 1);
            }
        }
        printf("\n  result: ");
        for (j = 0; j < n; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }

    printf("\nAfter: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}