#include <stdio.h>

struct Student {
    char name[20];
    int id;
    int score;
};

int main(void)
{
    struct Student s1;

    printf("name: ");
    scanf("%s", s1.name);

    printf("id: ");
    scanf("%d", &s1.id);

    printf("score: ");
    scanf("%d", &s1.score);

    printf("\n%s (%d) score = %d\n", s1.name, s1.id, s1.score);

    struct Student s2 = {"Tom", 2, 88};
    printf("%s (%d) score = %d\n", s2.name, s2.id, s2.score);

    return 0;
}