#include<stdio.h>
int INT_MAX=100000;

void floyd_warshall(int v,int adj[100][100]){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i!=j && i!=k && j!=k){
                    if(adj[i][j]>adj[i][k]+adj[k][j]){
                        adj[i][j]=adj[i][k]+adj[k][j];
                    }
                }
            }
        }
    }

    printf("\n final cost of the matrix is :\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j]==INT_MAX){
                printf("infinitibe");
            }
            else{
                printf("\t %d ",adj[i][j]);
            }
        }
        printf("\n");
    }
}
int main(){
    int v,adj[100][100];
        printf("\n enter the no of vertex:");
        scanf("%d",&v);
        printf("\n enter the adjacency matrix:\n");
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    scanf("%d",&adj[i][j]);
                    if(i!=j && adj[i][j]==0){
                        adj[i][j]=INT_MAX;
                    }
                }
            }
     floyd_warshall(v,adj);
    return 0;
}