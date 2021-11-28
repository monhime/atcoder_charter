#include<iostream>
#include<cstdio>


int selection_sort(int *A,int N){
    int i,j,t,sw=0,minj;

    for(i=0;i<N-1;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj])
                minj=j;
        }    
        std::swap(A[i],A[minj]);
        if(i!=minj)
            sw++;
    }
    return sw;

}

int main(void){
    int A[100],N,i,sw;

    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    
    sw=selection_sort(A,N);

    for(i=0;i<N;i++){
        if(i)
            putchar(' ');
        printf("%d",A[i]);
    }
    putchar('\n');
    printf("%d\n",sw);

    return 0;

}
