#include<iostream>
using namespace std;
int N,flag[101],ans;
int main(){
    cin>>N;
    for(i=0;i<N;i++){
        int d;
        cin>>d;
        flag[d]=1;

    }
    for(i=0;i<N;i++)
        ans+=flag[i];
    cout<<ans<<"\n";
    return 0;
}
