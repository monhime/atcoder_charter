#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m],b[m],c[n];
    //行列a入力
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }    
    }  
    //行列bの入力
    for(int j=0;j<m;j++){
        cin>>b[j];
    }            
    //行列cの初期化
    for(int i=0;i<n;i++){
        c[i]=0;
    }
    //行列計算・行列c表示
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c[i]+=a[i][j]*b[j];
        }
        cout<<c[i]<<"\n";
    }
}
