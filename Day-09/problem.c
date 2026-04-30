// Day 9 
#include <stdio.h>

void reverse(char str[], int start, int end) {
    if(start >= end) return;

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse(str, start + 1, end - 1);
}

int main() {
    char str[100];
    scanf("%s", str);

    int len = 0;
    while(str[len] != '\0') {
        len++;
    }

    reverse(str, 0, len - 1);

    printf("%s", str);

    return 0;
}