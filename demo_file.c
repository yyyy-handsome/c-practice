#include <stdio.h>

int main(void)
{
    FILE *fp;
    char name[20];
    int score;

    /* 1. 写：打开文件，写入两行，关闭 */
    fp = fopen("demo_data.txt", "w");
    if (fp == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    fprintf(fp, "LiMing 92\n");
    fprintf(fp, "WangHua 85\n");
    fclose(fp);

    /* 2. 读：重新打开，一次读一条，直到读不到为止 */
    fp = fopen("demo_data.txt", "r");
    if (fp == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    printf("read back:\n");
    while (fscanf(fp, "%s %d", name, &score) == 2) {
        printf("%s %d\n", name, score);
    }
    fclose(fp);

    return 0;
}