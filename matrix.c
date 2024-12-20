#include<stdio.h>
int main(){
    int a[100][100],b[100][100],c[100][100],d[100][100],e[100][100],m,n,p,q,sum,mul;
    printf("\n enter the no of rows and column of the first matrix:");
    scanf("%d %d",&m,&n);
    printf("\n enter the elements of the first matrix:");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n enter the no of rows and column of the second matrix:");
    scanf("%d %d",&p,&q);
    printf("\n enter the elements of the second matrix:");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&b[i][j]);
        }
    }
    
    printf("the first matrix is:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }


    printf("the first second is:\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d \t",b[i][j]);
        }
        printf("\n");
    }
 

 if(n!=p){
    printf("\n the matrix can not multiply.");
 }
 else{
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            sum=0;
            for(int k=0;k<m;k++){
                sum=sum+a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }


 printf("\n the matrix muttiplication is:\n");
 for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            printf("%d \t",c[i][j]);
        }
        printf("\n");
    }
 }

 if(m!=p && n!=q){
    printf("matrix can not be added");
 }
 else{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d[i][j]=a[i][j]+b[i][j];
        }
    }

printf("\n the matrix addition is:\n");
 for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d \t",d[i][j]);
        }
        printf("\n");
    }
 }

 if(m!=p && n!=q){
    printf("matrix can not be substruct");
 }
 else{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            e[i][j]=a[i][j]-b[i][j];
        }
    }

printf("\n the matrix substruction is:\n");
 for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d \t",e[i][j]);
        }
        printf("\n");
    }
 }


return 0;
}