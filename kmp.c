#include<stdio.h>
int p,t,lps[100];
char pattern[100],text[100];
void create_LPS(){
    int ind=1,len=0;
    lps[0]=0;
    while(ind<p){
        if(pattern[ind]==pattern[len]){
            lps[ind]=len+1;
            ind++;
            len++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[ind]=0;
                ind++;
            }
        }
    }
}
void kmp(){
    int i=0,j=0;
    while(i<t){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j==p){
            printf("\n\n given pattern is present in the text.");
            return ;
        }
    }
    printf("\n\n given pattern is not present in the text:");
}
int main(){
    printf("\n enter the length of the text:");
    scanf("%d",&t);
    printf("\n enter the length of the pattern:");
    scanf("%d",&p);
    printf("\n enter the all charcter of the 1st string:");
    for(int i=0;i<t;i++){
        scanf(" %c",&text[i]);
    }
    printf("\n enter the all charecter of the 2nd string:");
    for(int j=0;j<p;j++){
        scanf(" %c",&pattern[j]);
    }

    create_LPS();
    kmp();
    return 0;
}