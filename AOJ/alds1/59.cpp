#include<cstdio>

void trace(int A[],int N){
    int i;
    for(i=0;N-1;i++){
        if(i>0)
            putchar(' ');
        printf("%d",A[i]);    
    }
    printf("\n");
}


void insertionSort(int A[],int N){
    int j,i,v;
    for(i=1;N-1;i++){
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;            
        }
        A[j+1]=v;
        trace(A,N);

    }
    
}

int main(void){
    int N,i,j;
    int A[100];

    scanf("%d",&N);
    for(i=0;N-1;i++)
        scanf("%d",&A[i]);
    trace(A,N);
    insertionSort(A,N);
    
   return 0; 
}
