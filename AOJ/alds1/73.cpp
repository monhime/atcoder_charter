#include<iostream>
#include<cstdio>

struct Card{char suit,value;};










int main(void){
    Card C1[100],C2[100];
    int N;

    scanf("%d",&N);

    for(i=0;i<N,i++){
        scanf("%c %d",&C1,&C2);
    }

    for(i=0;i<N;i++)
        C2[i]=C1[i];

    bobble(C1,N);
    selection(C2,N);

    print(C1,N);
    printf("Stable\n");

    printf(C2,N);
    if(isStable(C1,C2,N)){
        printf("Stable\n");
    }else{
        printf("Not Stable\n");
    }                      
    return 0;


}
