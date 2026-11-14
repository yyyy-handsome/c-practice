#include <stdio.h>
#include <string.h>

struct student {
    char name[20];
    int id;
    int score;
};


int loadStudent (struct student stu[], int maxcount)
{
    FILE* fp;
    int count = 0;
    fp = fopen("D:\\Dev\\Code\\c-practice\\students.txt", "r");

    if (fp == NULL) {                        //如果fp打开为空，说明文件打开失败
        return 0;
    }

    while (count < maxcount &&
           fscanf(fp, "%s %d %d",
                  stu[count].name,
                  &stu[count].id,
                  &stu[count].score) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}


int saveStudents(struct student stu[], int count)
{
    FILE* fp;
    int i;

    fp = fopen("D:\\Dev\\Code\\c-practice\\students_review_sorted.txt", "w");
    if (fp == NULL) {
        return 0;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%s %d %d\n", stu[i].name, stu[i].id, stu[i].score);
    }

    fclose(fp);
    return 1;
}

void showAll (struct student stu[], int count)
{
    int i;

    if (count ==0){
        printf("no data\n");
    } else {
        for (i = 0; i < count; i++){
            printf("%s %d %d\n",stu[i].name,stu[i].id,stu[i].score);
        }
    }
}


void sortByScore (struct student stu[], int count)
{
    int i,j;
    struct student t;

    for (i = 0; i < count -1; i++){
        for (j = 0; j < count -1 -i; j++){                    //冒泡排序
            if (stu[j].score < stu[j +1].score){
                t = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] =t;
            }
        }
    }
}


struct student* findTop (struct student stu[],int count)
{
    if (count ==0){
        return NULL;                   //NULL是一个宏定义，表示空指针。这里表示如果没有学生就返回一个空指针。
    }

    struct student* top = &stu[0];

    for (int i = 1; i < count; i++){
        if (stu[i].score > top->score){               //这里的->是只top指针指向的结构体变量的成员
            top = &stu[i];
        }
    }
    return top;
}




struct student* findByName (struct student stu[], int count, char* name)
{
    for (int i = 0; i < count; i++){
        if (strcmp(stu[i].name,name) ==0){                    //strcmp函数是比较两个字符串是否相等，如果相等返回0.  用法时strcmp(字符串1，字符串2)  == 0就是找到相同的
            return &stu[i];                                  //返回stu[i]的地址，给函数
        }
    }
    return NULL;                                            //如果上述操作找不到相同的字符串(名字) 就返回空指针。
}


void searchByName (struct student stu[], int count){
    char name[20];
    printf("please input name:");
    scanf("%19s",name);
    struct student* found = findByName (stu,count,name);

    if (found != NULL){                                              //如果found成功接收到函数返回来的地址，就打印接受回来的地址里所含的值name id score
        printf("%s %d %d\n",found->name,found->id,found->score);
    } else {
        printf("no found\n");
    }
}



int main ()
{
    struct student stu[100];
    int count = loadStudent(stu,100);
    struct student* top = findTop(stu,count);

    if (top != NULL){
        printf("Top student: %s %d %d\n",top->name,top->id,top->score);
    }

    sortByScore(stu,count);
    showAll(stu,count);

    searchByName(stu,count);


    if (saveStudents(stu,count)) {
        printf("saved %d students\n",count);
    } else {
        printf("save failed\n");
    }
    return 0;
}