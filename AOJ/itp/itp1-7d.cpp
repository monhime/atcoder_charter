#include<iostream>
using namespace std;
int main(){
    int n,m,l,i,j,k;
    cin>>n>>m>>l;
    int a[n][m],b[m][l];
    long long c[n][l];
    //行列aの入力
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cin>>a[i][j];
    }
    //行列bの入力
    for(j=0;j<m;j++){
        for(k=0;k<l;k++)
            cin>>b[j][k];
    }           
    //行列cの初期化
    for(i=0;i<n;i++){
        for(k=0;k<l;k++)
            c[i][k]=0;
    }
    //行列cの出力
    for(i=0;i<n;i++){
        for(k=0;k<l;k++){
            for(j=0;j<m;j++){
                c[i][k]+=a[i][j]*b[j][k];
            }
            cout<<(k==0?"":" ")<<c[i][k];
        }
        cout<<"\n";
    }
    return 0;

}
