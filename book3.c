#include <stdio.h>
int main()
{
    char str[1000];
    // 数组n的5个元素分别对应0、2、4、6、8的计数，初始化为0
    int n[5] = {0};
    printf("请输入一个字符串：");
    gets(str); 

    for(int i=0; str[i]!='\0'; i++)
    {
        // 判断当前字符是否为数字字符
        if(str[i] >= '0' && str[i] <= '9')
        {
            int num = str[i] - '0'; // 字符转对应整型数字
            // 仅统计偶数数字
            if(num % 2 == 0)
            {
                // 映射下标：0→0、2→1、4→2、6→3、8→4
                n[num/2]++;
            }
        }
    }

    printf("各偶数数字出现次数：\n");
    printf("0出现次数：%d\n", n[0]);
    printf("2出现次数：%d\n", n[1]);
    printf("4出现次数：%d\n", n[2]);
    printf("6出现次数：%d\n", n[3]);
    printf("8出现次数：%d\n", n[4]);
    return 0;
}