#include<iostream>
#include<algorithm>
using namespace std;
int N;
int main(){
    cin>>N;
    int A[2][N];
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    int x[N];
    for(int i=0;i<N;i++)x[i]=0;

    for(int k=0;k<N;k++){
        for(int i=0;i<=k;i++) 
            x[k]+=A[0][i];
        for(int i=k;i<N;i++)
            x[k]+=A[1][i];
    }
    sort(x,x+N-1,greater<int>());
    cout<<x[0]<<"\n";
    return 0;
}
