#include <stdio.h>
#include <string.h>
int main()
{
    char strs[5][100], temp[100];
    // 输入5个字符串
    for(int i=0; i<5; i++)
    {
        printf("请输入第%d个字符串：", i+1);
        gets(strs[i]);
    }

    // 冒泡排序实现字符串降序，strcmp返回>0说明前一个字符串字典序更大
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4-i; j++)
        {
            if(strcmp(strs[j], strs[j+1]) < 0)
            {
                // 交换两个字符串
                strcpy(temp, strs[j]);
                strcpy(strs[j], strs[j+1]);
                strcpy(strs[j+1], temp);
            }
        }
    }

    printf("降序排列后的字符串：\n");
    for(int i=0; i<5; i++)
    {
        printf("%s\n", strs[i]);
    }
    return 0;
}