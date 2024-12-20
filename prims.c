#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int flag[100],p[100],key[100];


int extractMin(int v){
   int min_index=-1;
   int min_value=INT_MAX;
   for(int i=0;i<v;i++){
    if(flag[i]==0 && key[i]<min_value){
        min_value=key[i];
        min_index=i;
    }
   }
   return min_index;
}

void prims(int adj[100][100],int s,int v){
   int u;
    for(int i=0;i<v;i++){
        flag[i]=0;
        key[i]=INT_MAX;
        p[i]=-1;
    }

    key[s]=0;

  for(int count=0;count<v-1;count++){
    u=extractMin(v);
    if(u==-1)
    break;
    flag[u]=1;
         
         for(int i=0;i<v;i++){
            if(adj[u][i]!=0 && flag[i]==0 && adj[u][i]<key[i]){
                 key[i]=adj[100][100];
                 p[i]=u;
            }
         }
  }
  for(int i=0;i<v;i++){
    if(p[i]==-1){
        printf("\n this is root node",i+1);
    }
    else{
        printf("%d<==%d",p[i]+1,i+1);
    }
  }
}
int main() {
    int v, Adj[100][100], s, i, j;
    printf("\nEnter the total number of vertices: ");
    scanf("%d", &v);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            scanf("%d", &Adj[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &s);

    Prims(Adj, s - 1, v);

    return 0;
}
