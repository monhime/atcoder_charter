#include<iostream>
#include<algorithm>
using namespace std;
int A,B,C,X;
int ma,mb,mc,cunt;
int main(){
    cin>>A>>B>>C>>X;
    ma=X/500,mb=X/100,mc=X/50;
    for(int i=0;i<=min(ma,A);i++){
        for(int j=0;j<=min(mb,B);j++){
            for(int k=0;k<=min(mc,C);k++){
                if(50*k+100*j+500*i==X)cunt++;

            }
        }
    }
    cout<<cunt<<"\n";
    return 0;

}
