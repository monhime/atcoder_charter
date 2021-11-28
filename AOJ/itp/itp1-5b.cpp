#include<iostream>
using namespace std;
int main(){
    int i,j,H,W;

    while(cin>>H>>W&&!(H==0&&W==0)){
        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                cout<<((i==0||i==H-1||j==0||j==W-1)?"#":".");
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    return 0;
}
