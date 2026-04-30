// Day 37 
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int pq[100], size = 0;

    for(int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            pq[size++] = x;

        } else if(strcmp(op, "delete") == 0) {
            if(size == 0) {
                printf("-1\n");
                continue;
            }

            int minIndex = 0;
            for(int j = 1; j < size; j++) {
                if(pq[j] < pq[minIndex]) {
                    minIndex = j;
                }
            }

            printf("%d\n", pq[minIndex]);

            for(int j = minIndex; j < size - 1; j++) {
                pq[j] = pq[j + 1];
            }
            size--;

        } else if(strcmp(op, "peek") == 0) {
            if(size == 0) {
                printf("-1\n");
                continue;
            }

            int min = pq[0];
            for(int j = 1; j < size; j++) {
                if(pq[j] < min) {
                    min = pq[j];
                }
            }

            printf("%d\n", min);
        }
    }

    return 0;
}