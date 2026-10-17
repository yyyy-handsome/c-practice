#include <stdio.h>
#include <string.h>          /* strlen 在这个头文件里 */

int main(void)
{
    char word[100];          /* 最多放 99 个字符，最后 1 格留给 '\0' */
    int len;
    int i;

    printf("Please input a word: ");
    scanf("%s", word);       /* 数组名本身就是地址，不能写 &word */

    len = strlen(word);      /* 数到 '\0' 为止，不把 '\0' 算进去 */

    printf("word = %s\n", word);
    printf("length = %d\n", len);

    printf("reverse: ");
    /* 最后一个字符的下标是 len-1，一直打到下标 0 */
    for (i = len - 1; i >= 0; i--) {
        printf("%c", word[i]);       /* %c 打印单个字符 */
    }
    printf("\n");
    return 0;
}