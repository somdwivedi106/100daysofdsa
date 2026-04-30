// Day 54 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* nodes[100];

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    struct node* root = nodes[0];

    struct node* queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;

    int leftToRight = 1;

    while(front <= rear) {
        int size = rear - front + 1;
        int temp[100];

        for(int i = 0; i < size; i++) {
            struct node* curr = queue[front++];

            if(leftToRight)
                temp[i] = curr->data;
            else
                temp[size - 1 - i] = curr->data;

            if(curr->left) queue[++rear] = curr->left;
            if(curr->right) queue[++rear] = curr->right;
        }

        for(int i = 0; i < size; i++) {
            printf("%d ", temp[i]);
        }

        leftToRight = !leftToRight;
    }

    return 0;
}