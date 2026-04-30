// Day 28 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);

        if(head == NULL) {
            head = newnode;
            temp = newnode;
            newnode->next = head;
        } else {
            newnode->next = head;
            temp->next = newnode;
            temp = newnode;
        }
    }

    if(head == NULL) return 0;

    temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}