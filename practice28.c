#include <stdio.h>
#include <string.h>

int main(void){
    char word[100];
    int len;
    int i;

    printf("please input a word:");
    scanf("%s", word);            /* 字符串输入不加 & */

    len = strlen(word);

    printf("word = %s\n", word);
    printf("length = %d\n", len);

    /* 两头往中间比：左半边比完就够了，所以是 i < len/2 */
    for (i = 0; i < len/2; i++){
        if (word[i] != word[len-1-i]){    /* len-1-i 是右边对称的那个下标 */
            printf("不是回文数\n");
            return 0;                     /* 发现一对不相同，直接结束 */
        }
    }
    printf("是回文数\n");                 /* 能走到这里说明每一对都相同 */
    return 0;
}