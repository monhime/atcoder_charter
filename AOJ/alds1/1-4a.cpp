#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

bool search(int A[],int n,int key){
    int i=0;
    A[n]=key;
    while(A[i]!=key)i++;
    return i!=n;
}

int main(){
    int i,n,A[10001],q,key,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    cin>>q;
    for(i=0;i<q;i++){
        cin>>key;
        if(search(A,n,key))sum++;
    }
    cout<<sum<<"\n";
    return 0;
        
}
