#include <stdio.h>

/* ===== 结构体：把属于同一个学生的几样数据打包 =====

   struct Student 是一个"新类型"，地位和 int 一样。
   一个包裹里装三件东西：
        name  —— 姓名（字符数组，最多放 19 个字符 + 结尾的 '\0'）
        id    —— 学号
        score —— 成绩

   注意：右花括号后面那个分号是语法要求，漏了直接编译失败。 */
struct Student {
    char name[20];
    int id;
    int score;
};

int main(void)
{
    /* 结构体数组：3 个学生，每个元素都是一个完整的包裹
       stu[0] 是一个 Student，stu[1] 是一个 Student ……
       取包裹里的东西用点号：stu[0].score 读作"第 0 个学生的成绩" */
    struct Student stu[3];
    int i;
    int sum = 0;          /* 累加器，必须从 0 开始，否则是随机值 */

    printf("input 3 students (name id score):\n");

    /* ---- 第一个循环：读入 3 个学生 ---- */
    for (i = 0; i < 3; i++) {
        /* scanf 是往变量里"写"，所以普通成员前面必须加 &
           只有 name 不加：它是字符数组，数组名本身就是地址
           （和以前 scanf("%s", word) 的道理完全一样） */
        scanf("%s %d %d", stu[i].name, &stu[i].id, &stu[i].score);
    }

    /* ---- 第二个循环：逐个打印，同时累加成绩 ---- */
    for (i = 0; i < 3; i++) {
        /* printf 只是把值"读"出来显示，%d 前面不要加 &
           如果写成 &stu[i].id，打出来的会是地址，变成一串负数 */
        printf("%s %d %d\n", stu[i].name, stu[i].id, stu[i].score);

        /* 成绩藏在包裹里，必须写 stu[i].score；只写 score 是另一个变量 */
        sum = sum + stu[i].score;
    }

    /* 平均分：sum / 3 是整数除法，小数会被丢掉
       先乘 1.0 变成小数再除；%.2f 表示保留两位小数 */
    printf("avg = %.2f\n", sum * 1.0 / 3);

    return 0;
}