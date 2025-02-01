#include <stdio.h>

int product(int a, int b) {
    if (b == 1)
        return a;
    return a + product(a, b - 1);
}

int main() {
    int a, b;
    printf("Enter two numbers (a b): ");
    scanf("%d %d", &a, &b);
    printf("%d * %d = %d\n", a, b, product(a, b));
    return 0;
}
