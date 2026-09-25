#include <stdio.h>

int main(void){
    int a, b;
    printf("please input two integers:\n");
    scanf("%d %d",&a,&b);
    printf("a=%d,b=%d\n",a, b);

    printf("a+b=%d\n",a+b);
    printf("a-b=%d\n",a-b);
    printf("a*b=%d\n",a*b);
    printf("a/b=%d\n",a/b);

    double s=a/b;
    printf("s=%.2f\n",s);

    double s2=(double)a/b;
    printf("s2=%.2f\n",s2);

    printf("1:%d\n",a/b);
    printf("2:%.2f\n",a/(b*1.0));
    printf("3:%.2f\n",a/b*1.0);
    printf("余数:%d\n",a%b);
    return 0;    
    }