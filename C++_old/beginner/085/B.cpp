#include<iostream>
using namespace std;
int N,cunt,x;
int main(){
    cin>>N;
    int d[N];
    for(int i=0;i<N;i++){
        bool flag=1;
        cin>>x;
        for(int j=0;j<=cunt;j++)
            flag*=(d[j]!=x?1:0);
        if(flag==1){
            d[cunt]=x;
            cunt++;
        }
    }
    cout<<cunt<<"\n";
    return 0;


}
