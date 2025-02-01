#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int acc_number;
    char name[21];
    float balance;
} Customer;

int main() {
    Customer customers[200];
    int i = 0;
    for (; i < 200; i++) {
        customers[i].acc_number = 1000000000 + rand() % 100000000;
        sprintf(customers[i].name, "Customer%d", i + 1);
        customers[i].balance = rand() % 1000;
    }
    printf("Customers with balance under 100: -\n");
    for (i = 0; i < 200; i++)
        if (customers[i].balance < 100)
            printf("\tName: %s. Account number: %d\n", customers[i].name,
                   customers[i].acc_number);
    return 0;
}
