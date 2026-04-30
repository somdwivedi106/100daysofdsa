// Day 41 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct node *front = NULL, *rear = NULL;

    for(int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);

            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = x;
            newnode->next = NULL;

            if(front == NULL) {
                front = rear = newnode;
            } else {
                rear->next = newnode;
                rear = newnode;
            }

        } else if(strcmp(op, "dequeue") == 0) {
            if(front == NULL) {
                printf("-1\n");
            } else {
                struct node* temp = front;
                printf("%d\n", temp->data);
                front = front->next;
                free(temp);

                if(front == NULL) {
                    rear = NULL;
                }
            }
        }
    }

    return 0;
}