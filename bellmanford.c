#include <stdio.h>
#include <stdlib.h>

int d[100], INT_MAX = 100000;

void Initialisation(int v, int s) {
    int i;
    for(i = 0; i < v; i++) {
        d[i] = INT_MAX;
    }
    d[s] = 0;  
}

void Relaxation(int u, int v, int w) {
    if (d[u]!=INT_MAX && d[v] > d[u] + w) {
        d[v] = d[u] + w;
    }
}

int IsTrue(int v, int Adj[100][100]) {
    int u, w;
    for (u = 0; u < v; u++) {
        for (w = 0; w < v; w++) {
            if (Adj[u][w] != 0 && d[u] != INT_MAX && d[w] > d[u] + Adj[u][w]) {
                return 0; 
            }
        }
    }
    return 1; 
}

void Bellman_Ford(int Adj[100][100], int v, int s) {
    int i, u, w;
    Initialisation(v, s);

    
    for(i = 1; i <= v - 1; i++) {
        for (u = 0; u < v; u++) {
            for (w = 0; w < v; w++) {
                if (Adj[u][w] != 0) {  
                    Relaxation(u, w, Adj[u][w]);
                }
            }
        }
    }

    if (IsTrue(v, Adj)) {
        for (i = 0; i < v; i++) {
            if (i != s) {
                printf("\nMinimum cost to reach %d from %d is: %d", s+1, i+1, d[i]);
            }
        }
    } else {
        printf("\nThis graph contains a negative-weight cycle.");
    }
}

int main() {
    int v, Adj[100][100], i, j, s;

    printf("\nEnter the total number of vertices: ");
    scanf("%d", &v);

    printf("\nEnter the adjacency matrix:\n");
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
           scanf("%d", &Adj[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &s);

    Bellman_Ford(Adj, v, s-1);

    return 0;
}