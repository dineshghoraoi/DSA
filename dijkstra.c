#include<stdio.h>
#include<stdlib.h>
int p[100],d[100],f[100],stack[100],top=-1,INT_MAX=100000;
void initilization(int s,int v){
    for(int i=0;i<v;i++){
        d[i]=INT_MAX;
        f[i]=0;
        p[i]=-1;
    }
    d[s]=0;
}

int extractMin(int v){
    int min_index=-1;
    int min_value=INT_MAX;
    for(int i=0;i<v;i++){
        if(f[i]==0 && d[i]<min_value){
            min_value=d[i];
            min_index=i;
        }
    }
    return min_index;
}

void relaxation(int u,int v,int adj[100][100]){
    if(d[v]>(d[u]+adj[u][v]) && adj[u][v]!=0){
        d[v]=d[u]+adj[u][v];
        p[v]=u;
        }
}

int  isEmpty(int v){
   for(int i=0;i<v;i++){
    if(f[i]==0){
        return 1;
    }
   }
   return 0;
}

void push(int item){
    stack[++top]=item;
}

void pop(){
    top--;
}

void dijkstra(int s,int v,int adj[100][100]){
    int u,j,k;
    initilization(s,v);
    while(isEmpty(v)!=0){
        u=extractMin(v);
        if(u==-1){
            break;
        }
        f[u]=1;
        for(int i=0;i<v;i++){
            if(f[i]==0 && adj[u][i]!=0){
                relaxation(u,i,adj);
            }
        }
    }
    for(int i=0;i<v;i++){
        if(i!=s){
            printf("\n sortest path %d to %d:",s+1,i+1);
            push(i+1);
            j=i;
            while(p[j]!=-1){
                push(p[j]+1);
                j=p[j];
            }
            while(top!=-1){
                k=stack[top];
                pop();
                if(k==s+1){
                    printf("%d",k);
                }
                else{
                    printf("->%d",k);
                }
            }
        }
    }
}

int main(){
    int s,v,adj[100][100];
    printf("\n enter the no of vertex:");
    scanf("%d",&v);
    printf("\n enter the adjaceccy matrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\n enter the starting vertex:");
    scanf("%d",&s);

    dijkstra(s-1,v,adj);

    return 0;
}