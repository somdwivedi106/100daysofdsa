// Day 10 
#include <stdio.h>

int main() {
    char s[100];
    scanf("%s", s);

    int i = 0, len = 0;

    while(s[len] != '\0') {
        len++;
    }

    int j = len - 1;

    while(i < j) {
        if(s[i] != s[j]) {
            printf("NO");
            return 0;
        }
        i++;
        j--;
    }

    printf("YES");

    return 0;
}