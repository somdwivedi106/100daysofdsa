// Day 32 
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int stack[100], top = -1;

    for(int i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(top != -1) {
            top--;
        }
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}