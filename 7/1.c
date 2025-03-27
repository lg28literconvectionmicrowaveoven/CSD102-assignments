#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void push(Node *head, Node *element) {
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
}

Node pop(Node **head) {
    Node *temp = *head;
    *head = (*head)->next;
    return *temp;
}

int main() {
    char input[50];
    printf("Enter input postfix expression: ");
    scanf(" %[^\n]s", input);
    char *buf = strtok(input, " ");
    int result = atoi(buf);
    Node *operands_head = NULL;
    while ((buf = strtok(NULL, " ")) != NULL) {
        if (buf[0] >= '0' && buf[0] <= '9') {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->val = atoi(buf);
            new_node->next = NULL;
            if (operands_head == NULL)
                operands_head = new_node;
            else
                push(operands_head, new_node);
        } else if (buf[0] == '+' || buf[0] == '-' || buf[0] == '*' ||
                   buf[0] == '/') {
            switch (buf[0]) {
            case '+':
                result += pop(&operands_head).val;
                break;
            case '-':
                result -= pop(&operands_head).val;
                break;
            case '*':
                result *= pop(&operands_head).val;
                break;
            case '/':
                result /= pop(&operands_head).val;
                break;
            default:
                printf("Invalid operation %c.", buf[0]);
                break;
            }
        }
    }
    printf("The result of the given expression is: %d.", result);
    return 0;
}
