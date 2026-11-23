#include <stdio.h>
int main()
{
    char str[1000], target;
    printf("请输入原字符串：");
    gets(str);
    printf("请输入指定字符：");
    scanf("%c", &target);

    // 遍历查找目标字符第一次出现的位置
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i] == target)
        {
            break;
        }
    }

    // 如果找到目标字符，从下一位开始输出；否则提示未找到
    if(str[i] == target && str[i+1] != '\0')
    {
        printf("指定字符后的剩余字符：%s\n", &str[i+1]);
    }
    else
    {
        printf("未找到该指定字符或该字符是最后一位\n");
    }
    return 0;
}