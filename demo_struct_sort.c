#include <stdio.h>

struct Student {
    char name[20];
    int score;
};

int main(void)
{
    struct Student stu[5] = {
        {"LiMing", 92},
        {"WangHua", 85},
        {"ZhangWei", 78},
        {"ZhaoLei", 96},
        {"SunQi", 60}
    };
    int i, j;
    struct Student t;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (stu[j].score < stu[j + 1].score) {
                t = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = t;
            }
        }
    }

    printf("rank:\n");
    for (i = 0; i < 5; i++) {
        printf("%s %d\n", stu[i].name, stu[i].score);
    }
    return 0;
}