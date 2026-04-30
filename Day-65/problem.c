// Day 65 
#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

int dfs(int v, int parent) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i]) {
            if(!visited[i]) {
                if(dfs(i, v)) return 1;
            } else if(i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}