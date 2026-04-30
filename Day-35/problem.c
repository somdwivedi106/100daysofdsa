// Day 35 
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[100];
    int front = 0, rear = -1;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}