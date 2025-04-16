#include <stdio.h>
#include <stdlib.h>

typedef struct sn {
    int val;
    struct sn *next;
} StackNode;

int main() {
    char buf[10];
    StackNode *head1 = NULL;
    printf("Enter number 1: ");
    scanf("%s", buf);
    for (int i = 0; buf[i] != '\0'; i++) {
        StackNode *node = malloc(sizeof(StackNode));
        node->val = buf[i] - '0';
        node->next = head1;
        head1 = node;
    }
    StackNode *head2 = NULL;
    printf("Enter number 2: ");
    scanf("%s", buf);
    for (int i = 0; buf[i] != '\0'; i++) {
        StackNode *node = malloc(sizeof(StackNode));
        node->val = buf[i] - '0';
        node->next = head2;
        head2 = node;
    }
    StackNode *result = NULL;
    while (head1 != NULL || head2 != NULL) {
        StackNode *node = malloc(sizeof(StackNode));
        node->val = ((head1 == NULL) ? 0 : head1->val) +
                    ((head2 == NULL) ? 0 : head2->val);
        node->next = result;
        result = node;
        if (head1 != NULL)
            head1 = head1->next;
        if (head2 != NULL)
            head2 = head2->next;
    }
    printf("The sum of the two numbers is: ");
    while (result != NULL) {
        printf("%d", result->val);
        result = result->next;
    }
    return 0;
}
