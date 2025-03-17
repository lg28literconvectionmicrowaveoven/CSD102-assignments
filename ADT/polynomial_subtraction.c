#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float coef;
    float pow;
    void *next;
} PolyNode;

PolyNode *enter_polynomial() {
    PolyNode *head = NULL;
    PolyNode *tmp;
    float coef = 2;
    while (coef != 0) {
        printf("Enter coefficient: ");
        scanf("%f", &coef);
        if (coef == 0)
            break;
        PolyNode *new_node = (PolyNode *)malloc(sizeof(PolyNode));
        new_node->coef = coef;
        printf("Enter power: ");
        scanf("%f", &(new_node->pow));
        new_node->next = NULL;
        if (head == NULL)
            head = new_node, tmp = new_node;
        else {
            tmp->next = new_node;
            tmp = new_node;
        }
    }
    return head;
}

int main() {
    printf("Enter simplified polynomials without repeating coefficients: - "
           "(Enter 0 coefficient to stop)\nPolynomial 1: -\n");
    PolyNode *poly1 = enter_polynomial();
    printf("Polynomial 2\n");
    PolyNode *poly2 = enter_polynomial();
    PolyNode *ptr1 = poly1;
    PolyNode *result = NULL;
    while (ptr1 != NULL) {
        PolyNode *ptr2 = poly2;
        int found = 0;
        while (ptr2 != NULL) {
            if (ptr1->pow == ptr2->pow) {
                PolyNode *new_node = (PolyNode *)malloc(sizeof(PolyNode));
                new_node->coef = ptr1->coef - ptr2->coef;
                new_node->pow = ptr1->pow;
                new_node->next = NULL;
                if (result == NULL)
                    result = new_node;
                else {
                    result->next = new_node;
                    result = new_node;
                }
                found = 1;
                break;
            }
            ptr2 = ptr2->next;
        }
        if (!found) {
            PolyNode *new_node = (PolyNode *)malloc(sizeof(PolyNode));
            new_node->coef = ptr1->coef;
            new_node->pow = ptr1->pow;
            new_node->next = NULL;
            if (result == NULL)
                result = new_node;
            else {
                result->next = new_node;
                result = new_node;
            }
        }
        ptr1 = ptr1->next;
    }
    printf("Subtraction of the two polynomials is: -\n");
    while (result != NULL) {
        if (result->coef != 0)
            printf("%.2fx^%.2f ", result->coef, result->pow);
        result = result->next;
    }
    return 0;
}
