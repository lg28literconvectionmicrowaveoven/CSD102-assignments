#include <stdio.h>

int series_sum(int m, int n) {
    if (m == n)
        return m * m;
    return n * n + series_sum(m, n - 1);
}

int main() {
    int m, n;
    printf("Enter two numbers (m n): ");
    scanf("%d %d", &m, &n);
    printf("Sum of series: %d", series_sum(m, n));
    return 0;
}
