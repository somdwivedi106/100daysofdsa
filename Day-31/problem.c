// Day 31 
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stack[100], top = -1;

    for(int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if(op == 1) {
            int val;
            scanf("%d", &val);
            top++;
            stack[top] = val;
        } else if(op == 2) {
            if(top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top]);
                top--;
            }
        } else if(op == 3) {
            for(int j = top; j >= 0; j--) {
                printf("%d ", stack[j]);
            }
            printf("\n");
        }
    }

    return 0;
}