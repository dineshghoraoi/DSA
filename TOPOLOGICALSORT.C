#include<stdio.h>
int p[100],d[100],f[100],stack[100],top=-1,time=0;
char c[100];

void push(int item){
    stack[++top]=item;
}

void pop(){
    top--;
}

//dfs visit
void DFSvisit(int adj[100][100],int v,int u){
    c[u]='g';
    time++;
    d[u]=time;
    for(int i=0;i<v;i++){
        if(adj[u][i]!=0){
            if(c[i]=='w'){
                p[i]=u;
                DFSvisit(adj,v,i);
            }
        }
    }
    c[u]='b';
    push(u);
    time++;
    f[u]=time;
}

void dfs(int adj[100][100],int s,int v){
    for(int i=0;i<v;i++){
        c[i]='w';
        p[i]=-1;
        d[i]=0;
        f[i]=0;
    }

    if(c[s]=='w'){
        DFSvisit(adj,v,s);
    }
    for(int i=0;i<v;i++){
        if(c[i]=='w'){
            DFSvisit(adj,v,i);
        }
    }
}

void topologicalsort(int adj[100][100],int v,int s){
    dfs(adj,s-1,v);
    printf("topological sorting:");
    while(top!=-1){
       printf("%d ",stack[top]+1);
       pop();
    }
}

int main(){
    int v,s,adj[100][100];
    printf("\n enter the no of vertex:");
    scanf("%d",&v);
    printf("\n enter the value of adjacency matrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\n enter the starting vertex:");
    scanf("%d",&s);

    topologicalsort(adj,v,s);
    return 0;
}