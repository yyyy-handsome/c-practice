#include <stdio.h>

/* ============================================================
   成绩管理系统 v1.1

   数据平时放在内存里的结构体数组中；
   退出程序时写进 students.txt，下次启动时再读回来。
   所以关掉程序以后，数据不会丢。

   功能：1 新增  2 显示  3 按学号查询  4 统计
         5 按成绩排序  6 按学号删除  0 退出
   ============================================================ */

#define MAX 100          /* 最多能存 100 个学生，写超过就是越界 */
#define DATA_FILE "D:\\Dev\\Code\\c-practice\\students.txt"  /* 数据文件的完整路径 */

/* 一个 Student 包裹里装三样东西，右花括号后的分号不能漏 */
struct Student {
    char name[20];
    int id;
    int score;
};

int main(void)
{
    struct Student stu[MAX];   /* 真正存数据的地方：100 个空包裹 */
    int count = 0;             /* 已存数量，同时也是"下一个空位"的下标 */
    int choice, i;

    /* FILE 是标准库定义好的"文件"类型，内部结构对我们隐藏。
       我们只能拿到指向它的指针，也就是下面这个 fp（file pointer）。
       fp 本身是个指针，很多时候口语里直接叫它"文件句柄"。 */
    FILE *fp;

    /* ==========================================================
       启动时：把上次保存的数据读回内存

       fopen(文件名, "r") 以只读方式打开：
         文件存在   -> 返回可用的 FILE 指针
         文件不存在 -> 返回 NULL（第一次运行时就是这种情况，正常跳过）

       fscanf 的返回值和 scanf 一样，是"成功读到的项数"：
         返回 3 说明姓名、学号、成绩都读到了，这一条是完整的；
         读到文件末尾时返回 EOF，循环自动结束。
       ========================================================== */
    fp = fopen(DATA_FILE, "r");    //fopen(文件名, "r") 以只读方式打开：
    if (fp != NULL) {
        while (count < MAX &&
               fscanf(fp, "%s %d %d", stu[count].name,
                                     &stu[count].id,
                                     &stu[count].score) == 3) {
            count++;           /* 成功读一条，数量加一，下一条落到下一格 */
        }
        fclose(fp);            /* 用完必须关闭 */
        printf("loaded %d students from students.txt\n", count);
    }

    while (1) {                /* 1 永远为真，所以一直循环，靠 break 退出 */
        printf("\n===== score manager =====\n");
        printf("1. add student\n");
        printf("2. show all\n");
        printf("3. find by id\n");
        printf("4. stats\n");
        printf("5. sort by score\n");
        printf("6. delete by id\n");
        printf("0. exit\n");
        printf("choice: ");

        scanf("%d", &choice);

        if (choice == 0) {
            break;                     /* 跳出 while，去执行保存 */

        } else if (choice == 1) {
            /* ---------- 新增 ---------- */
            if (count >= MAX) {        /* 写之前先看还有没有空位 */
                printf("list is full\n");
            } else {
                printf("name id score: ");
                scanf("%s %d %d", stu[count].name, &stu[count].id, &stu[count].score);
                count++;
                printf("added\n");
            }

        } else if (choice == 2) {
            /* ---------- 显示 ---------- */
            if (count == 0) {
                printf("no data\n");
            } else {
                for (i = 0; i < count; i++) {
                    printf("%s %d %d\n", stu[i].name, stu[i].id, stu[i].score);
                }
            }

        } else if (choice == 3) {
            /* ---------- 按学号查询 ---------- */
            int id;
            int found = 0;             /* 0 表示还没找到 */

            printf("id: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++) {
                if (stu[i].id == id) {
                    printf("%s %d %d\n", stu[i].name, stu[i].id, stu[i].score);
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("not found\n");
            }

        } else if (choice == 4) {
            /* ---------- 统计 ---------- */
            int sum = 0;
            int max, min;

            if (count == 0) {
                printf("no data\n");
            } else {
                for (i = 0; i < count; i++) {
                    sum = sum + stu[i].score;
                }

                max = stu[0].score;
                min = stu[0].score;
                for (i = 1; i < count; i++) {
                    if (stu[i].score > max) max = stu[i].score;
                    if (stu[i].score < min) min = stu[i].score;
                }

                printf("max = %d  min = %d\n", max, min);
                printf("count = %d\n", count);
                printf("avg = %.2f\n", sum * 1.0 / count);
            }

        } else if (choice == 5) {
            /* ---------- 按成绩排序（冒泡，降序） ---------- */
            struct Student t;          /* 临时包裹，类型必须和元素一致 */
            int j;

            if (count == 0) {
                printf("no data\n");
            } else {
                for (i = 0; i < count - 1; i++) {
                    for (j = 0; j < count - 1 - i; j++) {
                        if (stu[j].score < stu[j + 1].score) {
                            /* 整个包裹一起换，只换 score 会让姓名错位 */
                            t = stu[j];
                            stu[j] = stu[j + 1];
                            stu[j + 1] = t;
                        }
                    }
                }
                printf("sorted\n");
            }

        } else if (choice == 6) {
            /* ---------- 按学号删除 ---------- */
            int j, p = -1;  //p=-1指的是还没找到在第几个
            int id;

            printf("id: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++) {
                if (stu[i].id == id) {
                    p = i;               //从p=-1到p=i可以知道此时下标是第几的时候id相同
                    break;
                }
            }

            if (p == -1) {
                printf("not found\n");
            } else {
                /* j 最大到 count-2，这样 stu[j+1] 最大才是 count-1（最后一个有效元素）
                   如果写成 j < count，最后会读到 stu[count] —— 那是还没用到的空位 */
                for (j = p; j < count - 1; j++) {
                    stu[j] = stu[j+1];   //知道j是我们要删去的学生信息，所以我们可以把后一个的信息赋给前一个实现  若j=1:(a b c d)➡(a c c d)
                }
                count--;             //放外面是因为只想把输入的那个学生的信息给删去！！ 可以删去最后那个下标的元素！！如果放循环里会多次减学生的数量！！
                printf("deleted\n");
            }

        } else {
            printf("invalid choice\n");
        }
    }

    /* ==========================================================
       退出时：把当前 count 条数据全部写回文件

       fopen(文件名, "w")：
         - "w" 表示写入，会先清空原文件，再从头写
         - 写进去的是当前完整状态，所以删掉的学生不会残留
         - 文件不存在时会自动创建

       fprintf 和 printf 的用法完全一样，
       只是第一个参数多了一个"写到哪个文件"。
       ========================================================== */
    fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        printf("save failed\n");
    } else {
        for (i = 0; i < count; i++) {
            fprintf(fp, "%s %d %d\n", stu[i].name, stu[i].id, stu[i].score);
        }
        fclose(fp);            /* 不关的话，缓冲区里的数据可能没真正写进磁盘 */
        printf("saved %d students to students.txt\n", count);
    }

    printf("bye\n");
    return 0;
}