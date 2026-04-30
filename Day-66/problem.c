// Day 66 
#include <stdio.h>

int adj[100][100];
int visited[100];
int recStack[100];
int n;

int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i]) {
            if(!visited[i] && dfs(i)) return 1;
            else if(recStack[i]) return 1;
        }
    }

    recStack[v] = 0;
    return 0;
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
            if(dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}