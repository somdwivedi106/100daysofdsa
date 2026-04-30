// Day 53 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct pair {
    struct node* node;
    int hd;
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

    int col[200][100];
    int count[200] = {0};

    struct pair queue[100];
    int front = 0, rear = -1;

    int offset = 100;

    queue[++rear] = (struct pair){root, 0};

    while(front <= rear) {
        struct pair p = queue[front++];
        struct node* curr = p.node;
        int hd = p.hd;

        col[hd + offset][count[hd + offset]++] = curr->data;

        if(curr->left)
            queue[++rear] = (struct pair){curr->left, hd - 1};
        if(curr->right)
            queue[++rear] = (struct pair){curr->right, hd + 1};
    }

    for(int i = 0; i < 200; i++) {
        if(count[i] > 0) {
            for(int j = 0; j < count[i]; j++) {
                printf("%d ", col[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}