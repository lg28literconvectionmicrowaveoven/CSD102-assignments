#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10];
    FILE *dat4 = fopen("DAT4", "r");
    int i = 0;
    if (dat4) {
        char buf[3];
        while (fgets(buf, 3, dat4)) {
            arr[i] = atoi(buf);
            if (arr[i] != 0)
                i++;
        }
        fclose(dat4);
    } else
        return -1;
    int count = 0;
    for (i = 0; i < 9; i++) {
        arr[i] = arr[i + 1];
        count++;
    }
    arr[9] = 0;
    printf("Array: ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\nCount: %d", count);
    return 0;
}
