#include <stdio.h>

void swap(int *a, int *b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

int main() {
    int a, b;
    printf("Enter integer a: ");
    scanf("%d", &a);
    printf("Enter integer b: ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("Swapped values: -\n\ta: %d\n\tb: %d", a, b);
    return 0;
}
