#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int A[1000000],n;

int binarySearch(int key){
    int left=0;
    int right=n;
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(key==A[mid])return 1;
        if(key>A[mid])left=mid+1;
        else if(key<A[mid])right=mid;
    }
    return 0;
}
int main(){
    int i,q,k,sum=0;

    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    cin>>q;
    for(i=0;i<q;i++){
        cin>>k;
        if(binarySearch(k))
            sum++;
    }   
    cout<<sum<<"\n";

    return 0;
        
}
