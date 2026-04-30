// Day 69 
#include <stdio.h>

#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int s;
    scanf("%d", &s);

    int dist[100], visited[100] = {0};

    for(int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[s] = 0;

    for(int count = 0; count < n; count++) {
        int u = -1, min = INF;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}