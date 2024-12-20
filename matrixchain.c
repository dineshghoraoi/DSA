#include<stdio.h>
int main(){
   int n,dim[100],m[100][100],s[100][100];
   printf("\n enter the no of elements you went to multiply:");
   scanf("%d",&n);
   printf("\n enter the dimensions:");
  for(int i=0;i<=n;i++){
   scanf("%d",&dim[i]);
  }
  for(int i=1;i<=n;i++){
   m[i][i]=0;
  }

  for(int l=2;l<=n;l++){
   for(int i=1;i<=n-l+1;i++){
      int j=i+l-1;
      m[i][j]=1000000;
      for(int k=i;k<j;k++){
         int z=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j];
         if(m[i][j]>z){
            m[i][j]=z;
            s[i][j]=k;
         }
      }
   }
  }

  for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++){
      if(i>=j){
         printf("  ");
      }
      else{
         printf(" %d",s[i][j]);
      }
   }
   printf("\n");
  }
  return 0;
}