#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    void *next;
} LinkedListNode;

void push(LinkedListNode **head, int val) {
    LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

void pop(LinkedListNode **head) {
    if (*head != NULL) {
        LinkedListNode *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void print_stack(LinkedListNode *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    LinkedListNode *head = NULL;
    push(&head, 9);
    push(&head, 5);
    push(&head, 20);
    pop(&head);
    push(&head, 6);
    pop(&head);
    push(&head, 10);
    print_stack(head);
    return 0;
}
