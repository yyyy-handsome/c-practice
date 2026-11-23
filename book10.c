#include <stdio.h>
#include <string.h>
int main()
{
    char strs[5][100]; // 存储5个字符串的二维数组
    int minLenIndex = 0; // 记录最短字符串的下标
    // 输入5个字符串
    for(int i=0; i<5; i++)
    {
        printf("请输入第%d个字符串：", i+1);
        gets(strs[i]);
    }

    // 遍历找出长度最短的字符串下标
    for(int i=1; i<5; i++)
    {
        if(strlen(strs[i]) < strlen(strs[minLenIndex]))
        {
            minLenIndex = i;
        }
    }

    // 对最短字符串进行逆序操作
    char shortStr[100];
    strcpy(shortStr, strs[minLenIndex]);
    int len = strlen(shortStr);
    for(int i=0; i<len/2; i++)
    {
        // 首尾交换字符实现逆序
        char temp = shortStr[i];
        shortStr[i] = shortStr[len-1 -i];
        shortStr[len-1 -i] = temp;
    }

    printf("最短字符串逆序后结果：%s\n", shortStr);
    return 0;
}