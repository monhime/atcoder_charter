#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int A[100000],n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    int q,k,sum=0;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>k;
        if(*lower_bound(A,A+n,k)==k)sum++;
    }
    cout<<sum<<"\n";
    return 0;
}
