#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define randint(min, max) (rand() % (max - min + 1) + min)

typedef struct {
    int id;
    int sub1_marks;
    int sub2_marks;
    int sub3_marks;
    int sub4_marks;
    int sub5_marks;
} Student;

int main() {
    Student arr[36];
    FILE *dat5 = fopen("DAT5", "r");
    char dat5_text[150];
    if (dat5) {
        fgets(dat5_text, 150, dat5);
        fclose(dat5);
    } else
        return -1;
    char *buf = strtok(dat5_text, " ");
    int i = 0;
    while (buf != NULL) {
        arr[i].id = atoi(buf);
        arr[i].sub1_marks = randint(0, 100);
        arr[i].sub2_marks = randint(0, 100);
        arr[i].sub3_marks = randint(0, 100);
        arr[i].sub4_marks = randint(0, 100);
        arr[i].sub5_marks = randint(0, 100);
        buf = strtok(NULL, " ");
        i++;
    }
    int target_index = 0;
    for (i = 0; i < 36; i++) {
        if (arr[i].id == 14)
            break;
    }
    int shifts = 0;
    for (i = target_index; i < 35; i++) {
        arr[i] = arr[i + 1];
        shifts++;
    }
    arr[35].id = 0;
    arr[35].sub1_marks = 0;
    arr[35].sub2_marks = 0;
    arr[35].sub3_marks = 0;
    arr[35].sub4_marks = 0;
    arr[35].sub5_marks = 0;
    printf("Number of shifts: %d.", shifts);
    return 0;
}
