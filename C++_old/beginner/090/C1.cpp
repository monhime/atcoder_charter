#include<iostream>
using namespace std;
typedef long long ll;
ll N,M;

int main(){
    cin>>N>>M;
    if(N>M)
        swap(N,M);
    if(N==1&M==1)
        cout<<1<<"\n";
    else if(N==1&M>1)
        cout<<M-2<<"\n";
    else
        cout<<(N-2)*(M-2)<<"\n";
    return 0;    
    
    
}
