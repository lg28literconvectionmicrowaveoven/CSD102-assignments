#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[20];
    FILE *file = fopen("SELECT1", "r");
    if (file) {
        char buf[10];
        int count = 0;
        while (fgets(buf, 10, file)) {
            arr[count] = atoi(buf);
            if (arr[count] != 0)
                count++;
        }
        fclose(file);
    }
    int moves = 0, i = 0;
    for (; i < 20; i++)
        printf("%d\n", arr[i]);
    for (i = 0; i < 19; i++) {
        int mindex = i;
        for (int j = i + 1; j < 20; j++)
            if (arr[j] < arr[mindex])
                mindex = j;
        int swap = arr[i];
        arr[i] = arr[mindex];
        arr[mindex] = swap;
        moves++;
    }
    FILE *output = fopen("SELECT2", "w");
    if (output) {
        printf("Array: ");
        for (i = 0; i < 20; i++) {
            fprintf(output, "%d\n", arr[i]);
            printf("%d ", arr[i]);
        }
        fclose(output);
        printf("\nMoves: %d\n", moves);
    } else
        return -1;
    return 0;
}
