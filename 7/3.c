#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
    printf("Enter expression: ");
    scanf(" %[^\n]s", input);
    int open_parantheses = 0;
    for (int i = 0; i < (int)strlen(input); i++) {
        if (input[i] == '(')
            open_parantheses++;
        else if (input[i] == ')')
            open_parantheses--;
        if (open_parantheses < 0) {
            printf("Invalid expression.");
            return 1;
        }
    }
    if (open_parantheses == 0)
        printf("The expression is balanced.");
    else
        printf("The expression is not balanced.");
    return 0;
}
