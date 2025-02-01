#include <stdio.h>

typedef struct {
    int date;
    int month;
    int year;
} date;

int main() {
    date date1;
    printf("Enter date 1 (dd mm yyyy): ");
    scanf("%d %d %d", &date1.date, &date1.month, &date1.year);
    date date2;
    printf("Enter date 2 (dd mm yyyy): ");
    scanf("%d %d %d", &date2.date, &date2.month, &date2.year);
    if (date1.date == date2.date && date1.month == date2.month &&
        date1.year == date2.year)
        printf("Equal\n");
    else
        printf("Unequal\n");
    return 0;
}
