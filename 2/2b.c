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
        customers[i].balance = 1000 + rand() % 100000;
    }
    int operation;
    printf("Enter operation (0 - withdrawal, 1 - deposit): ");
    scanf("%d", &operation);
    int target_acc;
    printf("Enter account number: ");
    scanf("%d", &target_acc);
    float amount;
    printf("Enter amount: ");
    scanf("%f", &amount);
    if (operation) {
        for (i = 0; i < 200; i++)
            if (customers[i].acc_number == target_acc) {
                customers[i].balance += amount;
                printf("New balance: %.2f\n", customers[i].balance);
                break;
            }
    } else {
        for (i = 0; i < 200; i++)
            if (customers[i].acc_number == target_acc) {
                if (customers[i].balance < amount)
                    printf("Insufficient balance\n");
                else {
                    customers[i].balance -= amount;
                    printf("New balance: %.2f\n", customers[i].balance);
                }
                break;
            }
    }
    return 0;
}
