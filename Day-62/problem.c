// Day 62 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct node* adj[100] = {NULL};

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct node* newnode1 = (struct node*)malloc(sizeof(struct node));
        newnode1->data = v;
        newnode1->next = adj[u];
        adj[u] = newnode1;

        struct node* newnode2 = (struct node*)malloc(sizeof(struct node));
        newnode2->data = u;
        newnode2->next = adj[v];
        adj[v] = newnode2;
    }

    for(int i = 0; i < n; i++) {
        printf("%d:", i);
        struct node* temp = adj[i];
        while(temp != NULL) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}