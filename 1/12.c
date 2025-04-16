#include <stdio.h>
#include <stdlib.h>

int main() {
    int ALLRAN[100];
    int i = 0, moves = 0;
    for (; i < 100; i++)
        ALLRAN[i] = rand() % 2000;
    for (i = 0; i < 99; i++) {
        int max_index = i;
        for (int j = i + 1; j < 100; j++)
            if (ALLRAN[j] > ALLRAN[max_index])
                max_index = j;
        int swap = ALLRAN[i];
        ALLRAN[i] = ALLRAN[max_index];
        ALLRAN[max_index] = swap;
        moves++;
    }
    FILE *file = fopen("SELECT4", "w");
    if (file) {
        for (i = 0; i < 100; i++)
            fprintf(file, "%d\n", ALLRAN[i]);
        fclose(file);
        printf("Moves: %d\n", moves);
    } else
        return -1;
}
