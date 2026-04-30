// Day 42 
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[100], stack[100];
    int front = 0, rear = -1, top = -1;

    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    front = 0;
    rear = -1;

    while(top != -1) {
        queue[++rear] = stack[top--];
    }

    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}