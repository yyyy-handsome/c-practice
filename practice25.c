#include <stdio.h>

int sumArray(int a[], int n){  //求和函数
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum +a[i];
    }
    return sum;
}


double average(int a[], int n){  //求平均函数
    return sumArray(a,n)*1.0/n;
}

int maxArray(int a[], int n){    //求最大函数
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}



int main(void){
    int s[5];
    printf("请输入五个整数: \n");
    for (int i = 0; i < 5; i++){
        scanf("%d",&s[i]);
    }
    printf("和=%d\n",sumArray(s,5));
    printf("平均数 = %.2f\n",average(s,5));
    printf("最大 = %d\n",maxArray(s,5));
    return 0;
}