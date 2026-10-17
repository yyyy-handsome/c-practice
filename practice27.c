#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[100];
    int len;
    int i;

    printf("Please input a word: ");
    scanf("%s", word);

    len = strlen(word);

    printf("word = %s\n", word);
    printf("length = %d\n", len);

    printf("reverse: ");
    /* TODO: 从最后一个字符开始，倒着打印到第一个字符 */
    for (i = len-1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
    return 0;
}