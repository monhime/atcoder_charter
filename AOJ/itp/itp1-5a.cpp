#include<iostream>
using namespace std;
int main(){
    int i,j,H,W;

    while(cin>>H>>W&&!(H==0&&W==0)){
        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                cout<<"#";
            }
            cout<<"\n";
        }
        cout<<endl;
    }
    return 0;
}

