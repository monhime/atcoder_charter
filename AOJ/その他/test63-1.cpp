#include<iostream>
using namespace std;
//バブルソート　in:配列、要素数 out:ソート回数
int bubble_sort(int *A,int N){
    int sw=0;
    int i,j;
    bool flag=1;

    for(i=0;flag;i++){
        flag=0;
        for(j=N-1;j>=i+1;j--){                             
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                flag=1;
                sw++;
            }                
        }
    }
    return sw;
}

int main(void){
    int A[100],i,j,N,sw;

    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];

    sw=bubble_sort(A,N);

    for(i=0;i<N;i++){
        if(i)
            cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<sw<<endl;

    return 0;
}
