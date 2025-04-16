#include <ctype.h>
#include <stdio.h>

#define SIZE 50

char buf[SIZE];
int top = -1;

void push(char elem) { buf[++top] = elem; }

char pop() { return buf[top--]; }

int priority(char elem) {
    switch (elem) {
    case '(':
        return 1;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 3;
    }
}

int main() {
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    push('(');
    while ((ch = infix[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
            while (buf[top] != '(')
                postfix[k++] = pop();
        else {
            while (priority(buf[top]) >= priority(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (buf[top] != '(')
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("Postfix expression: %s", postfix);
    return 0;
}
