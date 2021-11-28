#include<iostream>
using namespace std;
int main(){
    int n,b,f,r,v;

    int number[4][3][10];
    //初期化
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<10;k++)
                number[i][j][k]=0;
        }
    }
    //人数処理
    cin>>n;
    while(n){
        cin>>b>>f>>r>>v;
        number[b-1][f-1][r-1]+=v;
        n--;
        
    }

    //出力
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<10;k++)cout<<" "<<number[i][j][k];
            cout<<"\n";
        }
        if(i<3){
            for(int l=0;l<20;l++)cout<<"#";
        }    
        if(i<3)cout<<"\n";
    }
    return 0;
}
