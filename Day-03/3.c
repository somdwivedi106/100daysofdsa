#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    int c = 0;

    for(int i = 0; i < n; i++) {
        c++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d", c);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d", c);

    return 0;
}