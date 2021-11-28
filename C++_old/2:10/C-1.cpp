#include<iostream>
#include<cstdio>

int main(void){
    int i,N;
    int score=0;

    scanf("%d",N);
    int x[N],c[N],v[N];
    for(i=0;i<N;i++){
        scanf("%d",&x[i]);
    }
    for(i=0;i<N;i++){
        scanf("%d",&c[i]);
    }   
    for(i=0;i<N;i++){
        scanf("%d",&v[i]);
    }   

    



    for(i=0;i<N;i++){
        score+=v[i];
    }
    printf("%d",score);
    
}

