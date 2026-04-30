// Day 39 
#include <stdio.h>
#include <string.h>

int heap[100];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x) {
    int i = size++;
    heap[i] = x;

    while(i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin() {
    if(size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while(2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;

        if(right < size && heap[right] < heap[left]) {
            smallest = right;
        }

        if(heap[i] <= heap[smallest]) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return root;
}

int peek() {
    if(size == 0) return -1;
    return heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);

        } else if(strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());

        } else if(strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}