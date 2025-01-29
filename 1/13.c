#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[100];
    FILE *select4 = fopen("SELECT4", "r");
    if (select4) {
        char buf[10];
        int count = 0;
        while (fgets(buf, 10, select4)) {
            arr[count] = atoi(buf);
            if (arr[count] != 0)
                count++;
        }
        fclose(select4);
    } else
        return -1;
    int i = 0;
    for (i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (arr[i] == arr[j] && i != j) {
                arr[j]--;
                j--;
            }
    int moves = 0;
    for (i = 0; i < 99; i++) {
        int mindex = i;
        for (int j = i + 1; j < 100; j++) {
            if (arr[j] < arr[mindex])
                mindex = j;
        }
        int swap = arr[i];
        arr[i] = arr[mindex];
        arr[mindex] = swap;
        moves++;
    }
    FILE *select2 = fopen("SELECT2", "w");
    if (select2) {
        for (i = 0; i < 100; i++)
            fprintf(select2, "%d\n", arr[i]);
        fclose(select2);
        printf("Moves: %d\n", moves);
    } else
        return -1;
    return 0;
}
