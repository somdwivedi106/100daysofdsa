// Day 27 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct node* list1 = create(n);

    scanf("%d", &m);
    struct node* list2 = create(m);

    struct node *p1 = list1;

    while(p1 != NULL) {
        struct node *p2 = list2;

        while(p2 != NULL) {
            if(p1->data == p2->data) {
                printf("%d", p1->data);
                return 0;
            }
            p2 = p2->next;
        }

        p1 = p1->next;
    }

    printf("No Intersection");

    return 0;
}