#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    void *next;
} LinkedListNode;

LinkedListNode create_llist(int arr[], int n) {
    LinkedListNode *head = NULL;
    LinkedListNode *current = NULL;
    for (int i = 0; i < n; i++) {
        LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        node->value = arr[i];
        node->next = NULL;
        if (head == NULL) {
            head = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }
    return *head;
}

void ADDADD(LinkedListNode *head) {
    LinkedListNode *current = head;
    while (current != NULL) {
        current->value += 6;
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void SKIP(LinkedListNode head) {
    LinkedListNode *current = &head;
    int skip = 1;
    while (current != NULL) {
        if (skip % 2 == 1)
            printf("%d ", current->value);
        current = current->next;
        skip++;
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 24, 33, 40, 57, 68, 77};
    LinkedListNode head = create_llist(arr, 7);
    ADDADD(&head);
    SKIP(head);
    return 0;
}
