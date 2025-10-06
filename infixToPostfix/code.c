#include <stdio.h>
#include <ctype.h>
#define MAX 50

typedef struct stack {
    char items[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    s->items[++(s->top)] = c;
}
char pop(Stack *s) {
    return s->items[(s->top)--];
}
char peek(Stack *s) {
    return s->items[s->top];
}
int precedence(char symbol) {
    if (symbol == '^')
        return 3;
    if (symbol == '*' || symbol == '/')
        return 2;
    if (symbol == '+' || symbol == '-')
        return 1;
    return 0;
}
void infixToPostfix(char infix[]) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    char postfix[MAX], symbol;
    while (infix[i] != '\0') {
        symbol = infix[i];
        if (isalnum(symbol))
            postfix[j++] = symbol;
        else if (symbol == '(')
            push(&s, symbol);
        else if (symbol == ')') {
            while (s.top != -1 && peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s);
        }
        else {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(symbol))
                postfix[j++] = pop(&s);
            push(&s, symbol);
        }
        i++;
    }
    while (s.top != -1)
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
