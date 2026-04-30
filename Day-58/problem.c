// Day 58 
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

struct node* build(int preorder[], int inorder[], int start, int end, int *pIndex) {
    if(start > end) return NULL;

    struct node* root = newNode(preorder[(*pIndex)++]);

    if(start == end) return root;

    int index = find(inorder, start, end, root->data);

    root->left = build(preorder, inorder, start, index - 1, pIndex);
    root->right = build(preorder, inorder, index + 1, end, pIndex);

    return root;
}

void postorder(struct node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[100], inorder[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int pIndex = 0;

    struct node* root = build(preorder, inorder, 0, n - 1, &pIndex);

    postorder(root);

    return 0;
}