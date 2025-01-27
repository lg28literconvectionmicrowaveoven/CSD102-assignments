#include <stdio.h>
#include <stdlib.h>

int main() {
    int RAN[20];
    int i = 0;
    for (; i < 20; i++)
        RAN[i] = rand() % 500;
    int key, j, moves = 0;
    for (i = 1; i < 20; i++) {
        key = RAN[i];
        j = i - 1;
        while (j >= 0 && RAN[j] < key) {
            RAN[j + 1] = RAN[j];
            j = j - 1;
        }
        RAN[j + 1] = key;
        moves++;
    }
    FILE *file = fopen("SELECT3", "w");
    if (file) {
        for (i = 0; i < 20; i++)
            fprintf(file, "%d\n", RAN[i]);
        fclose(file);
        printf("Moves: %d\n", moves);
    } else
        return -1;
    return 0;
}
