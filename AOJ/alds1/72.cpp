#include<cstdio>
#include<iostream>

using namespace std;
struct Card{char suit,value;};
             
void bobble_sort(struct Card A[],int N){
    Card t;
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=i+1;j--){
            if(A[j].value<A[j-1].value)
                t=A[j];A[j]=A[j-1];A[j-1]=t;
        }
    }
}

void selection_sort(struct Card A[],int N){
    Card t;

    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A[j].value<A[minj].value)
                minj=j;
        }
        t=A[i];A[i]=A[minj];A[minj]=t;
    }
}

void print(struct Card A[],int N){
    for(int i=0;i<N;i++){
        if(i)
            putchar(' ');
        printf("%c%c",A[i].suit,A[i].value);
    }
    putchar('\n');
} 


bool isStable(struct Card C1[],struct Card C2[],int N){
    for(int i=0;i<N;i++){
        if(C1[i].suit!=C2[i].suit)
            return false;
    }
    return true;
}

int main(){
    Card C1[100],C2[100];
    int N;
    
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%c%c",&C1[i].suit,&C1[i].value);

    for(int i=0;i<N;i++)
        C2[i]=C1[i];
    
    bobble_sort(C1,N);
    selection_sort(C2,N);

    print(C1,N);
    printf("Stable\n");
    print(C2,N);
    if(isStable(C1,C2,N))
        printf("Stable\n");
    else
        printf("Not Stable\n");
    
    return 0;
}
