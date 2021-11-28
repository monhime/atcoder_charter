#include<iostream>
#include<algorithm>
using namespace std;
int N;
int x;
int main(){
    cin>>N;
    int A[100];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }    

    sort(A,A+N,greater<int>());
    for(int i=0;i<N;i++)x+=A[i]*(i%2!=1?1:-1);
    cout<<x<<"\n";
}
