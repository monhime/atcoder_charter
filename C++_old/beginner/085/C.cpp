#include<iostream>
using namespace std;
int N,Y;
int main(){
    cin>>N>>Y;
    int y=Y/1000;
    for(int i=N;i>=0;i--){
        if(y<10*i)continue;
        int A=y-10*i;
        for(int j=N-i;j>=0;j--){
            if(A<5*j)continue;
            int B=A-5*j;
            int k=N-i-j;
            if(B==k){
                cout<<i<<' '<<j<<' '<<k<<"\n";
                return 0;
                    
            }
        }
    }
    cout<<"-1"<<' '<<"-1"<<' '<<"-1"<<"\n";
    return 0;

    
}
