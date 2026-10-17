#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[6] = "hello";
    int i;

    printf("s = [%s]\n", s);
    printf("sizeof(s) = %d\n", (int)sizeof(s));
    printf("strlen(s) = %d\n\n", (int)strlen(s));

    for (i = 0; i < 6; i++) {
        printf("s[%d] = '%c'   ASCII = %d\n", i, s[i], s[i]);
    }
    printf("\n");

    for (i = 0; s[i] != '\0'; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}