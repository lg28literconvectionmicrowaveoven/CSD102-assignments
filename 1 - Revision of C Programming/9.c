#include <stdio.h>
#include <stdlib.h>

int main() {
    int RAN[20];
    int i = 0;
    for (; i < 20; i++)
        RAN[i] = rand() % 500;
    int searches = 0, moves = 0;
    for (i = 0; i < 19; i++) {
        int mindex = i;
        for (int j = i + 1; j < 20; j++) {
            if (RAN[j] < RAN[mindex])
                mindex = j;
            searches++;
        }
        int swap = RAN[i];
        RAN[i] = RAN[mindex];
        RAN[mindex] = swap;
        moves++;
    }
    FILE *file = fopen("SELECT1", "w");
    if (file) {
        for (i = 0; i < 20; i++)
            fprintf(file, "%d\n", RAN[i]);
        fclose(file);
    }
    printf("Searches: %d\nMoves: %d\n", searches, moves);
    return 0;
}
