#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

int main() {
    int m, s;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    scanf("%d", &s);

    int queue[100];
    int front = 0, rear = -1;

    visited[s] = 1;
    queue[++rear] = s;

    while(front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    return 0;
}