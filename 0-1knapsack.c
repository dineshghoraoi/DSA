#include<stdio.h>

int m,n;



int max(int x,int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

struct object{
    int profit,weight;
}objects[100];

void o_1_knapsack(){
    int v[100][100];
    for(int i=0;i<=n;i++){
         v[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        v[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<objects[i].weight){
                v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=max(v[i-1][j],(v[i-1][j-objects[i].weight]+objects[i].profit));
            }
        }
    }
    printf("\n totl profit is:%d\n",v[n][m]);
}
int main(){
    printf("\n enter the no of objects:");
    scanf("%d",&n);
    printf("\n enter the weight limit:");
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        printf("\n\n enter the profit for object no%d: ",i);
        scanf("%d",&objects[i].profit);
        printf("\n\n enter the weight for object no:%d: ",i);
        scanf("%d",&objects[i].weight);
    }
    o_1_knapsack();
    return 0;
}