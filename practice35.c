#include <stdio.h>

struct Student {
    char name[20];
    int score;
};

void sortByScore(struct Student *stu, int n)
{
    int i, j;
    struct Student t;  //t和stu的类型一样都是结构体 所以可交换存

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (stu[j].score<stu[j+1].score){
                t = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = t;
            }
            /* TODO: 如果 stu[j].score 比 stu[j+1].score 小，就交换两个包裹 */
        }
    }
}

int main(void)
{
    struct Student stu[5];
    int i;

    for (i = 0; i < 5; i++) {
        scanf("%s %d", stu[i].name, &stu[i].score);
    }

    sortByScore(stu, 5);

    for (i = 0; i < 5; i++) {
        printf("%s %d\n", stu[i].name, stu[i].score);
    }
    return 0;
}