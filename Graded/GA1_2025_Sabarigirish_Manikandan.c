#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tourist {
    char first_name[21];
    char last_name[21];
    int id;
    int status;
    struct tourist *next;
} Tourist;

void print_tourist_list(Tourist *head) {
    Tourist *tmp = head;
    while (tmp != NULL) {
        printf("%d %s %s ", tmp->id, tmp->first_name, tmp->last_name);
        tmp = tmp->next;
    }
    printf("\n");
}

Tourist *create_tourist(char *first_name, char *last_name, int id, int status) {
    Tourist *new_tourist = malloc(sizeof(Tourist));
    strcpy(new_tourist->first_name, first_name);
    strcpy(new_tourist->last_name, last_name);
    new_tourist->id = id;
    new_tourist->status = status;
    new_tourist->next = NULL;
    return new_tourist;
}

void append_tourist(Tourist **head, Tourist *new_tourist) {
    if (*head == NULL)
        *head = new_tourist;
    else {
        Tourist *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_tourist;
    }
}

void insert_sorted(Tourist **head, Tourist *new_tourist) {
    if (*head == NULL || (*head)->id > new_tourist->id) {
        new_tourist->next = *head;
        *head = new_tourist;
    } else {
        Tourist *current = *head;
        while (current->next != NULL && current->next->id < new_tourist->id)
            current = current->next;
        new_tourist->next = current->next;
        current->next = new_tourist;
    }
}

void remove_tourist_by_name(Tourist **head, char *first_name, char *last_name) {
    Tourist *temp = *head;
    Tourist *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->first_name, first_name) == 0 &&
            strcmp(temp->last_name, last_name) == 0) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    Tourist *BOOKING_head = NULL;
    Tourist *TRIP_head = NULL;
    Tourist *WAITLIST_head = NULL;
    int bookings = 0, trips = 0, waitlist_count = 0;
    FILE *fptr = fopen("EASYTRIP.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file EASYTRIP.txt\n");
        return 1;
    }
    char line[100];
    fgets(line, 100, fptr);
    int max_trips = atoi(line);
    while (fgets(line, 100, fptr)) {
        line[strcspn(line, "\n")] = 0;
        switch (line[0] - '0') {
        case 1: {
            char first_name[21];
            char last_name[21];
            strtok(line, " ");
            strcpy(first_name, strtok(NULL, " "));
            strcpy(last_name, strtok(NULL, " "));
            int id = atoi(strtok(NULL, " "));
            Tourist *new_booking = create_tourist(first_name, last_name, id, 0);
            insert_sorted(&BOOKING_head, new_booking);
            bookings++;
            if (trips < max_trips) {
                Tourist *trip_tourist =
                    create_tourist(first_name, last_name, id, 1);
                insert_sorted(&TRIP_head, trip_tourist);
                trips++;
                new_booking->status = 1;
            } else {
                Tourist *last_trip = TRIP_head;
                Tourist *prev_to_last = NULL;
                while (last_trip->next != NULL) {
                    prev_to_last = last_trip;
                    last_trip = last_trip->next;
                }
                if (last_trip->id > id) {
                    Tourist *to_waitlist =
                        create_tourist(last_trip->first_name,
                                       last_trip->last_name, last_trip->id, 2);
                    Tourist *temp = BOOKING_head;
                    while (temp != NULL) {
                        if (temp->id == last_trip->id) {
                            temp->status = 2;
                            break;
                        }
                        temp = temp->next;
                    }
                    prev_to_last->next = NULL;
                    free(last_trip);
                    Tourist *trip_tourist =
                        create_tourist(first_name, last_name, id, 1);
                    insert_sorted(&TRIP_head, trip_tourist);
                    new_booking->status = 1;
                    insert_sorted(&WAITLIST_head, to_waitlist);
                    waitlist_count++;
                } else {
                    Tourist *waitlist_tourist =
                        create_tourist(first_name, last_name, id, 2);
                    insert_sorted(&WAITLIST_head, waitlist_tourist);
                    new_booking->status = 2;
                    waitlist_count++;
                }
            }
            break;
        }
        case 2: {
            char first_name[21];
            char last_name[21];
            strtok(line, " ");
            strcpy(first_name, strtok(NULL, " "));
            strcpy(last_name, strtok(NULL, " "));
            Tourist *temp = BOOKING_head;
            int status = -1;
            while (temp != NULL) {
                if (strcmp(temp->first_name, first_name) == 0 &&
                    strcmp(temp->last_name, last_name) == 0) {
                    status = temp->status;
                    break;
                }
                temp = temp->next;
            }
            if (status == 1) {
                remove_tourist_by_name(&BOOKING_head, first_name, last_name);
                remove_tourist_by_name(&TRIP_head, first_name, last_name);
                bookings--;
                trips--;
                if (waitlist_count > 0) {
                    Tourist *waitlist_first = WAITLIST_head;
                    WAITLIST_head = WAITLIST_head->next;
                    waitlist_count--;
                    Tourist *book_temp = BOOKING_head;
                    while (book_temp != NULL) {
                        if (book_temp->id == waitlist_first->id) {
                            book_temp->status = 1;
                            break;
                        }
                        book_temp = book_temp->next;
                    }
                    waitlist_first->status = 1;
                    waitlist_first->next = NULL;
                    append_tourist(&TRIP_head, waitlist_first);
                    trips++;
                }
            } else if (status == 2) {
                remove_tourist_by_name(&BOOKING_head, first_name, last_name);
                remove_tourist_by_name(&WAITLIST_head, first_name, last_name);
                bookings--;
                waitlist_count--;
            }
            break;
        }
        case 3:
            printf("BOOKING ");
            print_tourist_list(BOOKING_head);
            break;
        case 4:
            printf("TRIP ");
            print_tourist_list(TRIP_head);
            break;
        case 8:
            printf("WAITLIST ");
            print_tourist_list(WAITLIST_head);
            break;
        default:
            printf("Invalid operation code.\n");
            break;
        }
    }
    fclose(fptr);
    return 0;
}
