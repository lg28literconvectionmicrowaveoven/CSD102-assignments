#include <stdio.h>
#include <stdlib.h>

// TODO: close the files dumbass

int main() {
    int arr[10];
    FILE *dat4 = fopen("DAT4", "r");
    if (dat4) {
        char buf[3];
        int count = 0;
        while (fgets(buf, 3, dat4)) {
            arr[count] = atoi(buf);
            if (arr[count] != 0)
                count++;
        }
        printf("Array: ");
        for (count = 0; count < 10; count++)
            printf("%d ", arr[count]);
        printf("\nReversed Array: ");
        for (count = 0; count < 10; count++)
            printf("%d ", arr[9 - count]);
        fclose(dat4);
    } else
        return -1;
    return 0;
}
