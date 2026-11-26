#include <stdio.h>
#include <string.h>
#define MAX 100


struct Students {
    char name[20];
    int id;
    float score;
};


int loadStudents (struct Students* stu,int MAXcount)
{
    FILE* fp;
    int count = 0;
    fp = fopen ("score.txt","r");
    if (fp == NULL){
        printf("cannot open file\n");
        return -1;
    }


    while (count < MAXcount && 
            fscanf(fp,"%s %d %f",
                    stu[count].name,
                    &stu[count].id,
                    &stu[count].score) == 3){
        count++;
    }
    fclose(fp);
    printf("loaded %d student to score.txt\n",count);
    return count;
}


double Average (struct Students *stu,int count)
{
    double sum = 0;
    for (int i = 0; i < count; i++){
        sum =sum + stu[i].score;
    }
    return sum*1.0 / count;
}


struct Students* findMAX (struct Students stu[MAX],int count)
{
    if (count <= 0) return NULL;

    struct Students* p =stu;
    struct Students* best = &stu[0];

    for (p = stu + 1;p < stu + count; p++){
        if (best->score < p->score){
            best = p;
        }
    }

    return best;
}


/* 把每条记录写进文件，格式：姓名 成绩 PASS/FAIL
   函数需要什么就传什么：需要数组、条数、平均分（用来判断 PASS/FAIL）、文件名 */
void saveToFile (struct Students *stu, int count, double avg, const char *filename)
{
    FILE* fp;
    struct Students *p;

    /* "w" = 写入，会先清空原文件；文件不存在会自动创建 */
    fp = fopen (filename, "w");
    if (fp == NULL){
        printf("cannot open %s\n", filename);
        return;
    }

    /* 指针遍历：p 从第一个走到最后一个 */
    for (p = stu; p < stu + count; p++){
        if (p->score >= avg){
            fprintf (fp, "%s %.0f PASS\n", p->name, p->score);
        } else {
            fprintf (fp, "%s %.0f FAIL\n", p->name, p->score);
        }
    }

    /* 文件用完必须关闭，否则缓冲区里的数据可能没真正写进磁盘 */
    fclose (fp);
    printf("saved to %s\n", filename);
}


int main(void)
{
    struct Students stu[MAX];
    int count = 0;

    count = loadStudents (stu,MAX);

    if (count == -1){
        printf("open exit\n");
        return 1;
    }

    if (count == 0){
        printf("no data\n");
        return 0;
    }

    double avg = Average (stu,count);

    struct Students* top = findMAX (stu,count);
    if (top == NULL){
        printf("no data\n");
        return 0;
    }

    printf("count=%d avg=%.2f max=%s(%.0f)\n",count,avg,top->name,top->score);

    saveToFile (stu, count, avg, "result.txt");
    return 0;
}
