#include<stdio.h>
#include<stdlib.h>

int p[100],r[100];

struct edge{
    int u,v;
    int weight;
}edges[100];

struct solution{
    int u,v;
    int weight;
}solution[100];

int solution_count=0;

int findSet(int x){
    if(p[x]!=x){
        p[x]=findSet(p[x]);
    }
    return p[x];
}

void link(int a,int b){
    if(r[a]>r[b]){
        p[b]=a;
    }
    else{
        p[a]=b;
        if(r[a]==r[b]){
            r[b]++;
        }
    }
}

void Union(int u,int v){
    link(findSet(u),findSet(v));
}

void makeSet(int e){
    for(int i=0;i<e;i++){
        p[i]=i;
        r[i]=0;
    }
}

void kruskals(struct edge edges[100],int e){
    int x,y;
    for(int i=0;i<e;i++){
        x=findSet(edges[i].u);
        y=findSet(edges[i].v);

        if(x!=y){
            Union(x,y);

            solution[solution_count].u=edges[i].u;
            solution[solution_count].v=edges[i].v;
            solution[solution_count].weight=edges[i].weight;
            solution_count++;
        }
    }
    for (int i = 0; i < solution_count; i++) {
        printf("\nEdge no %d:\n\tStarting vertex: %d\n\tEnding vertex: %d\n\tEdge weight: %d", 
                i + 1, solution[i].u, solution[i].v, solution[i].weight);
}
}

int main(){
    int e;
    printf("\n enter the total no of edges:");
    scanf("%d",&e);
    printf("\nENTER THE EDGES IN ASCENDING ORDER OF THEIR WEIGHT:\n");
    for (int i = 0; i < e; i++) {
        printf("\nEnter the starting vertex of edge no %d: ", i + 1);
        scanf("%d", &edges[i].u);

        printf("Enter the ending vertex of edge no %d: ", i + 1);
        scanf("%d", &edges[i].v);

        printf("Enter the weight of edge no %d: ", i + 1);
        scanf("%d", &edges[i].weight);
    }
    makeSet(e);
    kruskals(edges,e);
    return 0;
}