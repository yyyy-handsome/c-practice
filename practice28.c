#include <stdio.h>
#include <string.h>

int main(void){
    char word[100];
    int len;
    int i;

    printf("please input a word:");
    scanf("%s", word);

    len = strlen(word);

    printf("word = %s\n", word);
    printf("length = %d\n", len);

    for (i = 0; i < len/2; i++){
        if (word[i] != word[len-1-i]){
            printf("不是回文数\n");
            return 0;
        }
    }
    printf("是回文数\n");
    return 0;
}