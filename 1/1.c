#include <stdio.h>

int firstValue(int x, int y) { return x; }

int secondValue(int x, int y) { return y; }

int main() {
    int a, b;
    printf("Enter integer a: ");
    scanf("%d", &a);
    printf("Enter integer b: ");
    scanf("%d", &b);
    printf("Swapped values: -\n\ta: %d\n\tb: %d", firstValue(a, b),
           secondValue(a, b));
    return 0;
}
