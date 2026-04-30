// Day 51 
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

struct node* insert(struct node* root, int val) {
    if(root == NULL) return newNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

struct node* lca(struct node* root, int n1, int n2) {
    if(root == NULL) return NULL;

    if(n1 < root->data && n2 < root->data)
        return lca(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return lca(root->right, n1, n2);

    return root;
}

int main() {
    int n, x, n1, n2;
    scanf("%d", &n);

    struct node* root = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &n1, &n2);

    struct node* ans = lca(root, n1, n2);

    if(ans != NULL)
        printf("%d", ans->data);

    return 0;
}