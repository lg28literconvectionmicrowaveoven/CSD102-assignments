#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    void *next;
} LinkedListNode;

LinkedListNode *create_llist(int arr[], int n) {
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
    return head;
}

void PRINTPRINT(LinkedListNode head) {
    LinkedListNode *current = &head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 24, 33, 40, 57, 68, 77};
    LinkedListNode *head = create_llist(arr, 7);
    LinkedListNode *tmp = head->next;
    free(head);
    head = tmp;
    LinkedListNode *next = head->next;
    LinkedListNode *previous;
    while (next->next != NULL) {
        previous = tmp;
        tmp = next;
        next = next->next;
    }
    free(next);
    tmp->next = NULL;
    printf("Contents of A: -\n");
    PRINTPRINT(*head);
    printf("Second last node: %d\n", previous->value);
    tmp = head;
    while (tmp->next != NULL) {
        if (tmp->value > ((LinkedListNode *)tmp->next)->value)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
