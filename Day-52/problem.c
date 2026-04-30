// Day 52 
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

struct node* build(int arr[], int n) {
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

    return nodes[0];
}

struct node* lca(struct node* root, int a, int b) {
    if(root == NULL) return NULL;

    if(root->data == a || root->data == b)
        return root;

    struct node* left = lca(root->left, a, b);
    struct node* right = lca(root->right, a, b);

    if(left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    struct node* root = build(arr, n);

    struct node* ans = lca(root, a, b);

    if(ans != NULL)
        printf("%d", ans->data);

    return 0;
}