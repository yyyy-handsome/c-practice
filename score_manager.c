#include <stdio.h>

#define MAX 100

struct Student {
    char name[20];
    int id;
    int score;
};

int main(void)
{
    struct Student stu[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== score manager =====\n");
        printf("1. add student\n");
        printf("2. show all\n");
        printf("0. exit\n");
        printf("choice: ");

        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            /* TODO 1: 读入一个学生的姓名、学号、成绩，存进 stu[count]，然后 count++ */
        } else if (choice == 2) {
            /* TODO 2: 打印 count 个学生；如果 count == 0，提示还没有数据 */
        } else {
            printf("invalid choice\n");
        }
    }

    printf("bye\n");
    return 0;
}