// Day 34 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** top, int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node** top) {
    struct node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {
    char expr[100];
    struct node* top = NULL;

    fgets(expr, sizeof(expr), stdin);

    for(int i = 0; expr[i] != '\0'; i++) {
        if(expr[i] == ' ' || expr[i] == '\n') continue;

        if(isdigit(expr[i])) {
            push(&top, expr[i] - '0');
        } else {
            int b = pop(&top);
            int a = pop(&top);
            int res;

            if(expr[i] == '+') res = a + b;
            else if(expr[i] == '-') res = a - b;
            else if(expr[i] == '*') res = a * b;
            else if(expr[i] == '/') res = a / b;

            push(&top, res);
        }
    }

    printf("%d", pop(&top));

    return 0;
}