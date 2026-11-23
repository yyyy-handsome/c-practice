#include <stdio.h>
int main()
{
    char str[1000], res[1000];
    int j = 0;
    printf("请输入一个带空格的字符串：");
    gets(str);

    for(int i=0; str[i]!='\0'; i++)
    {
        // 非空格字符就存入结果数组
        if(str[i] != ' ')
        {
            res[j++] = str[i];
        }
    }
    res[j] = '\0'; // 手动添加字符串结束符

    printf("删除空格后的字符串：%s\n", res);
    return 0;
}