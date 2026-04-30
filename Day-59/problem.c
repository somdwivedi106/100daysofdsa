// Day 59 
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

int find(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val) return i;
    }
    return -1;
}

struct node* build(int inorder[], int postorder[], int start, int end, int *pIndex) {
    if(start > end) return NULL;

    struct node* root = newNode(postorder[(*pIndex)--]);

    if(start == end) return root;

    int index = find(inorder, start, end, root->data);

    root->right = build(inorder, postorder, index + 1, end, pIndex);
    root->left = build(inorder, postorder, start, index - 1, pIndex);

    return root;
}

void preorder(struct node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[100], postorder[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int pIndex = n - 1;

    struct node* root = build(inorder, postorder, 0, n - 1, &pIndex);

    preorder(root);

    return 0;
}