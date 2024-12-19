#include<stdio.h>

int n,board[100],col[100],ld[100],rd[100],nos=0;

void placeQueen(int i){
if(i>n){
    return;
}
else{
    for(int j=1;j<=n;j++){
        if(col[j]==0 && ld[i-j+n]==0 && rd[i+j-1]==0){
            board[i]=j;
            col[j]=ld[i-j+n]=rd[i+j-1]=1;
            if(i<n){
                placeQueen(i+1);
            }
            else{
                for(int k=1;k<=n;k++){
                    printf(" %d",board[k]);
            }
                    printf("\n");
                    nos++; 
                
            }
            col[j]=ld[i-j+n]=rd[i+j-1]=0;

        }
    }
}
}


int main(){
    printf("\n enter the no of queen:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        col[i]=board[i]=0;
    }
    for(int i=1;i<=2*n;i++){
        ld[i]=rd[i]=0;
    }
    placeQueen(1);
    printf("\n total no of solution :%d",nos);
    return 0;
}