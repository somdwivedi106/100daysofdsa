// Day 68 
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100] = {0};
    int indegree[100] = {0};

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    int queue[100];
    int front = 0, rear = -1;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while(front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adj[v][i]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    return 0;
}