// Day 38 
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int dq[100], front = -1, rear = -1;

    for(int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if(strcmp(op, "push_front") == 0) {
            int x;
            scanf("%d", &x);

            if(front == -1) {
                front = rear = 0;
                dq[front] = x;
            } else {
                front--;
                dq[front] = x;
            }

        } else if(strcmp(op, "push_back") == 0) {
            int x;
            scanf("%d", &x);

            if(front == -1) {
                front = rear = 0;
                dq[rear] = x;
            } else {
                rear++;
                dq[rear] = x;
            }

        } else if(strcmp(op, "pop_front") == 0) {
            if(front == -1 || front > rear) {
                printf("Empty\n");
            } else {
                front++;
            }

        } else if(strcmp(op, "pop_back") == 0) {
            if(front == -1 || front > rear) {
                printf("Empty\n");
            } else {
                rear--;
            }

        } else if(strcmp(op, "front") == 0) {
            if(front == -1 || front > rear) {
                printf("-1\n");
            } else {
                printf("%d\n", dq[front]);
            }

        } else if(strcmp(op, "back") == 0) {
            if(front == -1 || front > rear) {
                printf("-1\n");
            } else {
                printf("%d\n", dq[rear]);
            }

        } else if(strcmp(op, "size") == 0) {
            if(front == -1 || front > rear) {
                printf("0\n");
            } else {
                printf("%d\n", rear - front + 1);
            }

        } else if(strcmp(op, "empty") == 0) {
            if(front == -1 || front > rear) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }

    if(front != -1 && front <= rear) {
        for(int i = front; i <= rear; i++) {
            printf("%d ", dq[i]);
        }
    }

    return 0;
}