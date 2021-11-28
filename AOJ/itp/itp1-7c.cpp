#include<iostream>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    int a[r][c];
    int sum[c];
    int sum_all=0;
    //行列の行の和の初期化
    for(int j=0;j<c;j++)
        sum[j]=0;


    //行列Aの入力・出力・行の和の出力
    for(int i=0;i<r;i++){
        int sumc =0;
        for(int j=0;j<c;j++){
            cin>>a[i][j];
            sumc+=a[i][j];          //行の和
            cout<<a[i][j]<<" ";
            sum[j]+=a[i][j];//列の和
        }
        cout<<sumc<<"\n";
    }
    for(int j=0;j<c;j++){
        cout<<sum[j]<<" ";
        sum_all+=sum[j];
    }
    cout<<sum_all<<"\n";
    return 0;
}
