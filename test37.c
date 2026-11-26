#include <stdio.h>

int main(){
    int a[1000];
    int i,j,n;
    scanf("%d",&n);

    for (i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    int cur = 1,bestlen = 1;
    for (j = 1; j < n; j++){
        if (a[j] > a[j - 1]){
            cur++;
        } else {
            cur = 1;
        }
        if (cur > bestlen)  bestlen = cur;
    }
    printf("maxLen=%d\n",bestlen);
    return 0;
}