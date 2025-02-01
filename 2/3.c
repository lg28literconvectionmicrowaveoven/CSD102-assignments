#include <stdio.h>

typedef struct {
    int code;
    char name[21];
    int day;
    int month;
    int year;
} Employee;

int main() {
    Employee employees[100];
    int i = 0;
    for (; i < 100; i++) {
        employees[i].code = 1000 + i;
        sprintf(employees[i].name, "Employee%d", i + 1);
        employees[i].day = 1 + i % 31;
        employees[i].month = 1 + i % 12;
        employees[i].year = 2020 + i % 5;
    }
    int day, month, year;
    printf("Enter current date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    printf("Employees with 3 or more years of experience: -\n");
    for (i = 0; i < 100; i++) {
        if (year - employees[i].year >= 3)
            printf("Name: %s\tYear: %d\n", employees[i].name,
                   employees[i].year);
        else if (year == employees[i].year)
            if (month >= employees[i].month)
                printf("Name: %s\tYear: %d\n", employees[i].name,
                       employees[i].year);
    }
    return 0;
}
