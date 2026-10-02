#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
// 2.
    /*char NAME[50]; 
	printf("请输入你的名字:\n",NAME);
	scanf("%s",&NAME);
	printf("NAME:%s\n",NAME);*/
	
	
// 3.
	/*int r;
	double PI=3.14,C;
	printf("请输入半径:",r);
	scanf("%d",&r);
	C=2*PI*r;
	printf("C=%.2f",C);*/


// 4.
	/*char a,b;
	printf("请输入字符:");
	scanf("%c %c",&a,&b);
	printf("%d %d",a,b); */


// 5.
	/*int a,b,t;
	printf("请输入两个数字:\n");
	scanf("%d %d",&a,&b); 
	t=a;
	a=b;
	b=t;
	printf("%d,%d\n",a,b);*/

	
// 6.
	/*int a,b,c;
	printf("请输入三个整数:\n");
	scanf("%d %d %d",&a,&b,&c);
	if(a<b&&a<c){
		printf("min=a");
	}else if(b<c){
		printf("min=b");
	}else{
		printf("min=c");
	}*/

	
// 7.
	/*int num=0x12a;
	printf("%d\n",num);*/


// 8.
	/*int x;
	printf("请输入成绩:\n");
	scanf("%d",&x);
	//printf("%s",x>=60?"pass":"fail");
	if(x>=60){
		printf("pass");
	}else{
		printf("fail");
	}*/

	
// 9.
	/*int year;
	printf("请输入年份:\n");
	scanf("%d",&year);
	if((year%4==0&&year%100 !=0)||(year%400==0)){
		printf("%d是闰年",year);
	}else{
		printf("%d不是闰年",year);
	}*/


// 10
	/*int a,b,c;
	printf("输入三条边的数:\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("%s",a+b>c&&a-b<c?"yes":"no");*/

	
// 11.
	/*int x,y,z,min0,max0,mid0;
	printf("请按从小到大顺序输入三个数:\n");
	scanf("%d %d %d",&x,&y,&z);
    min0=(x<y?x:y)<z?(x<y?x:y):z;
    max0=(x>y?x:y)>z?(x>y?x:y):z;
    mid0=x+y+z-max0-min0;
	printf("min0=%d\n",min0);
	printf("max0=%d\n",max0);
	printf("mid0=%d\n",mid0);*/

// 12.
	int x,y;;
	printf("输入一个坐标:\n");
	scanf("%d %d",&x,&y);
	printf("%s",x*x+y*y<=1?"yes":"no");
	return 0;
}
