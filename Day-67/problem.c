// Day 67 
#include <stdio.h>

int adj[100][100];
int visited[100];
int stack[100];
int top = -1;
int n;

void dfs(int v) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = v;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    while(top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}