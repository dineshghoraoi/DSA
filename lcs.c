#include<stdio.h>

int max(int x,int y){
    if(x>y){
        return x;
    }
    else{
      return y;
    }
}

void LCS(char x[100],char y[100],int m,int n){
    int i,j,lcs[100][100];
    for( i=0;i<=n;i++){
        lcs[i][0]=0;
    }
    for( j=0;j<=m;j++){
        lcs[0][j]=0;
    }
    for(i=1;i<=n;i++){
        for( j=1;j<=m;j++){
            if(y[i]==x[j])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else{
                lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
            }
        }
    }
    printf("\n the largest subsequence is :%d\n",lcs[n][m]);
}

int main(){
    int m,n,i,j;
    char x[100],y[100];
    printf("\n enter the length of the 1st string:\n");
    scanf("%d",&m);
    printf("\n enter the length of the 2nd string:\n");
    scanf("%d",&n);
    printf("\n enter the all charecter of the 1st string:");
    for(i=1;i<=m;i++){
        scanf(" %c",&x[i]);
    }


   printf("\n\nEnter all the characters of the 2nd string: ");
    for (j = 1; j <= n; j++) {
        scanf(" %c", &y[j]); 
    }
    LCS(x,y,m,n);
    return 0;
}