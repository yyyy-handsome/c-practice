#include <stdio.h>


struct Student {
    char name[20];
    int score;
};

void AddBouns (struct Student *stu, int n, int bouns) {    //n是学生的人数。bouns是分数。
    for (int i = 0; i < n; i++) {
        stu[i].score = stu[i].score + bouns;       //bouns表示分数。。。函数意思是给学生加分数！！
    }
}


void ShowAll (struct Student *stu, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d\n",stu[i].name, stu[i].score);
    }
}



struct Student* findtop (struct Student *stu, int n) {         //函数表示返回一个指向结构体的指针，指向分数最高的学生。
    struct Student* top = &stu[0];           //给出同是结构体的指针存储
    for (int i = 1; i< n; i++) {
        if (stu[i].score > top->score) {    //如果stu[i]的分数大于top的分数，就把stu[i]的地址赋给top，使top指向分数最高的学生的地址
            top = &stu[i];
        }
    }
    return top;
}



int main(void)
{   
    int choice;
    struct Student stu[3];

    printf("请输入三个人的名字和分数:\n");
    for (int i =0; i < 3; i++){
        scanf("%s %d",stu[i].name,&stu[i].score);
    }
    while (1) {
        printf("1. add\n");
        printf("2. show\n");
        printf("3. find top\n");
        printf("4. exit\n");
        printf("choice:");
        scanf("%d", &choice);

        if (choice ==1) {
            AddBouns(stu, 3, 10);
        } else if (choice == 2) {
            ShowAll (stu,3);
        } else if (choice ==3) {
            struct Student* top = findtop(stu, 3);
            printf("Top student: %s %d %p\n", top->name, top->score,top);
        } else {
            break;
        }
    }
    return 0;
}