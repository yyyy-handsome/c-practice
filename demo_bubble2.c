#include <stdio.h>

int main(void)
{
    int a[5] = {5, 2, 9, 1, 7};
    int n = 5;
    int i, j, t;

    printf("start: %d %d %d %d %d\n\n", a[0], a[1], a[2], a[3], a[4]);

    for (i = 0; i < n - 1; i++) {
        printf("=== Round %d ===\n", i + 1);
        for (j = 0; j < n - 1 - i; j++) {
            printf("compare a[%d]=%d and a[%d]=%d : ", j, a[j], j + 1, a[j + 1]);
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                printf("left is bigger -> SWAP\n");
            } else {
                printf("ok, keep\n");
            }
            printf("   now: %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
        }
        printf("end of round %d\n\n", i + 1);
    }
    return 0;
}