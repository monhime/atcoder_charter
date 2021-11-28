#include<stdlib.h>
#include<stdio.h>
int N,M,cunt;
int main(){
    scanf("%d%d",&N,&M);  
    int** flag;
    flag=(int**)calloc(N+2,sizeof(int*));
    for(int i=0;i<N+2;i++)
        flag[i]=(int*)calloc(M+2,sizeof(int));
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
                flag[i-1][j-1]++;
                flag[i-1][j]++;
                flag[i-1][j+1]++;
                flag[i][j-1]++;
                flag[i][j]++;
                flag[i][j+1]++;
                flag[i+1][j-1]++;
                flag[i+1][j]++;
                flag[i+1][j+1]++;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cunt+=(flag[i][j]&1?1:0);
        }
    }
    printf("%d",cunt);                           
    for(int i=0;i<N+2;i++)free(flag[i]);
    free(flag);    
    return 0;
}
