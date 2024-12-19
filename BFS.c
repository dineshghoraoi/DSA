#include<stdio.h>
#include<stdlib.h>
int queue[100];
int front=-1;
int rear=-1;
void enqueue(int item){
    if(front==-1&&rear==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=item;
}

void dequeue(){
    if(front!=-1){
        front++;
    }
}
void BFS(int Adj[100][100],int s,int v){
    int p[100],d[100];
    char c[100];
    int u;
    for(int i=0;i<v;i++){
        c[i]='w';
        d[i]=0;
        p[i]=0;
    }
    c[s]='g';
    p[s]=0;
    enqueue(s);

    while(front<=rear){
        u=queue[front];
        dequeue();
        printf(" %d",u+1);

        for(int j=0;j<v;j++){
            if(Adj[u][j]==1 && c[j]=='w'){
                 c[j]='g';
                 p[j]=u;
                 d[j]=d[u]+1;
                 enqueue(j);
            }
        }
        c[u]='b';
    }
}


int main(){
    int v,s,Adj[100][100];
    printf("\n enter the no of total vartex:");
    scanf("%d",&v);
    printf("\n enter the value of adjacency matrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&Adj[i][j]);
        }
    }
    printf("\n enter the starting vertex:\n");
    scanf("%d",&s);
    BFS(Adj,s-1,v);
    return 0;
}