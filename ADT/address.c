#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name[20];
    long int ph_nbr;
    char email[20];
    struct node *next;
} node;

node *start_ptr = NULL;

void new_data() {
    node *new_node, *ptr;
    new_node = (node *)malloc(sizeof(node));
    printf("\tEnter name: ");
    scanf(" %[^\n]s", new_node->name);
    printf("\tEnter phone number: ");
    scanf("%ld", &new_node->ph_nbr);
    printf("\tEnter email: ");
    scanf(" %[^\n]s", new_node->email);
    new_node->next = NULL;
    if (start_ptr == NULL)
        start_ptr = new_node;
    else {
        ptr = start_ptr;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
}

void output_data() {
    node *ptr;
    ptr = start_ptr;
    printf("\n");
    while (ptr != NULL) {
        printf("\tName: %s\n", ptr->name);
        printf("\tPhone number: %ld\n", ptr->ph_nbr);
        printf("\tEmail: %s\n\n", ptr->email);
        ptr = ptr->next;
    }
}

int main() {
    int choice;
    do {
        printf("\nEnter your choice\n"
               "1. New Address data\n"
               "2. Display Address Book\n"
               "3. Exit\n: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            new_data();
            break;
        case 2:
            output_data();
            break;
        case 3:
            exit(0);
        }
    } while (choice != 3);
    return 0;
}
