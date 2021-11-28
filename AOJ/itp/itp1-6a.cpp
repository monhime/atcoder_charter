#include<iostream>
using namespace std;

int main(){
    int n,j;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<(i==0?"":" ")<<a[n-i-1];
    }
    cout<<"\n";
    return 0;


}
