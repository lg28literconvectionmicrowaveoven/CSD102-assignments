#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int arr[36];
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
        arr[i] = atoi(buf);
        buf = strtok(NULL, " ");
        i++;
    }
    int to_search[] = {66, 88, 97, 34, 40, 54, 24, 99, 73};
    int searches_arr[9];
    for (i = 0; i < 9; i++) {
        int searches = 0;
        printf("Searching for %d: -", to_search[i]);
        int mid = 17, left = 0, right = 35;
        while (left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] < to_search[i])
                left = mid + 1;
            else if (arr[mid] > to_search[i])
                right = mid - 1;
            else
                break;
            searches++;
        }
        if (mid < 36)
            printf("\n\t%d found at index %d.\n\tNumber of searches: %d.\n",
                   to_search[i], mid, searches);
        else
            printf("\n\t%d not found.\n", to_search[i]);
        searches_arr[i] = searches;
    }
    int max = 0;
    for (i = 0; i < 9; i++)
        if (max < searches_arr[i])
            max = searches_arr[i];
    printf("The maximum number of searches conducted for a number are %d.",
           max);
    return 0;
}
