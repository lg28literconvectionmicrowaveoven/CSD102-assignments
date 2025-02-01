#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll;
    char name[21];
    char dept[4];
    char course[11];
    int year;
} Student;

int main() {
    Student students[450];
    int i = 0;
    for (; i < 450; i++) {
        students[i].roll = rand() % 1000;
        sprintf(students[i].name, "Student%d", i + 1);
        strcpy(students[i].dept, "CSE");
        strcpy(students[i].course, "B.Tech");
        students[i].year = 2000 + rand() % 26;
    }
    int target;
    printf("Enter year to search for: ");
    scanf("%d", &target);
    for (i = 0; i < 450; i++)
        if (students[i].year == target)
            printf("Name: %s\n", students[i].name);
    return 0;
}
