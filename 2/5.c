#include <stdio.h>
#include <string.h>

typedef struct {
    char title[21];
    char author[21];
    int access_number;
} Book;

typedef struct {
    char authors[21][50];
    Book books[20][50];
} Library;

int main() {
    Library library;
    int author_census = 0, book_census = 0, loop_status = 1;
    printf("Welcome to the library!\n");
    while (loop_status) {
        int choice;
        printf("\t1. Add book information\n"
               "\t2. List all books of given author\n"
               "\t3. List the count of books in the library\n"
               "\t4. List the books in order of access number\n"
               "\t5. Exit\n: ");
        scanf("%d", &choice);
        if (choice == 1) {
            char author[21];
            char title[21];
            printf("Enter author name: ");
            scanf(" %[^\n]s", author);
            printf("Enter title: ");
            scanf(" %[^\n]s", title);
            for (int i = 0; i < author_census + 1; i++) {
                if (i == author_census) {
                    int j = 0;
                    for (; j < 50; j++)
                        if (library.books[i][j].title[0] == '\0')
                            break;
                    strcpy(library.authors[j], author);
                    strcpy(library.books[i][j].author, author);
                    strcpy(library.books[i][j].title, title);
                    library.books[j][0].access_number = (i + 1) * 10 + j + 1;
                    printf("New author %s added.\nNew book %s added to %s "
                           "collection.\n",
                           author, title, author);
                    author_census++;
                    book_census++;
                    break;
                } else if (strcmp(author, library.authors[i]) == 0) {
                    int j = 0;
                    for (; j < 50; j++)
                        if (library.books[i][j].title[0] == '\0')
                            break;
                    j++;
                    strcpy(library.books[i][j].author, author);
                    strcpy(library.books[i][j].title, title);
                    library.books[i][j].access_number = (i + 1) * 10 + j + 1;
                    printf("New book %s added to %s collection.\n", title,
                           author);
                    book_census++;
                    break;
                }
            }
        } else if (choice == 2) {
            char author[21];
            printf("Enter author name: ");
            scanf(" %[^\n]s", author);
            for (int i = 0; i < author_census + 1; i++) {
                if (i == author_census) {
                    printf("Author not found.\n");
                    break;
                } else if (strcmp(author, library.authors[i]) == 0) {
                    printf("%s collection: -\n", author);
                    for (int j = 0; j < 50; j++) {
                        if (library.books[i][j].title[0] == '\0')
                            break;
                        printf("\t%s\n", library.books[i][j].title);
                    }
                    break;
                }
            }
        } else if (choice == 3)
            printf("There are %d book(s) in the library.\n", book_census);
        else if (choice == 4) {
            // Simply looping over as accession number is already in order
            printf("Books in order of access number: -\n");
            for (int i = 0; i < author_census; i++) {
                printf("%s: -\n", library.authors[i]);
                for (int j = 0; j < 50; j++) {
                    if (library.books[i][j].title[0] == '\0')
                        break;
                    printf("\t%s\n", library.books[i][j].title);
                }
            }
        } else if (choice == 5)
            loop_status = 0;
        printf("\nSelect operation: -\n");
    }
    return 0;
}
