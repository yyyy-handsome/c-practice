
#include <stdio.h>
#include <string.h>
// 实现插入功能的自定义函数
void insertHash(char str[])
{
    char temp[2000] = {0}; // 临时数组存储结果，预留足够空间
    int j = 0;
    for(int i=0; str[i]!='\0'; i++)
    {
        temp[j++] = str[i];
        // 如果当前字符是数字，额外追加一个#
        if(str[i] >= '0' && str[i] <= '9')
        {
            temp[j++] = '#';
        }
    }
    strcpy(str, temp); // 将临时数组内容覆盖回原字符串
}

int main()
{
    char str[2000] = "Hello23are4y5o6u7";
    insertHash(str);
    printf("处理后字符串：%s\n", str);
    return 0;
}