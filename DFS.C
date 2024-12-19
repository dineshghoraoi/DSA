#include <stdio.h>
char c[100];
int p[100], d[100], f[100],time = 0;
    
void DFSVisit(int Adj[100][100], int v, int u) {
    c[u] = 'g';  
    time++;
    d[u] = time; 
    printf("%d ", u+1); 

    for (int i = 0; i < v; i++) {
        if (Adj[u][i] != 0) { 
            if (c[i] == 'w') { 
                p[i] = u;
                DFSVisit(Adj, v, i);
            }
        }
    }

    c[u] = 'b'; 
    time++;
    f[u] = time; 
}

void DFS(int Adj[100][100], int s, int v) {
    
    for (int i = 0; i < v; i++) {
        c[i] = 'w'; 
        p[i] = -1;  
        d[i] = 0;
        f[i] = 0;
    }

    
    if (c[s] == 'w') {
        DFSVisit(Adj, v, s);
    }

    
    for (int i = 0; i < v; i++) {
        if (c[i] == 'w') { 
            DFSVisit(Adj, v, i);
        }
    }
}

int main() {
    int v, Adj[100][100], s;

    printf("\nEnter the total no of vertices: ");
    scanf("%d", &v);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &Adj[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &s);

    printf("DFS traversal starting from vertex %d:\n", s);
    DFS(Adj, s - 1, v); 

    return 0;
}