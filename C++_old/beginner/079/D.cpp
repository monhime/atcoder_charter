#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
//#include <bits/stdc++.h>
using namespace std;
static const int MAX=100000;
int H,W,ans,A;
int c[10][10];

void solve(){
    for(int k=0;k<9;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){  
                if(j==1||j==i)continue;
                if(c[i][1]>c[i][j]+c[j][1])
                    c[i][1]=c[i][j]+c[j][1];
            }

        }
    }
}

int main(){
    cin>>H>>W;
    for(int i=0;i<10;i++){
        for(int j=0 ;j<10;j++){
            cin>>c[i][j];
        }
    }
    solve();
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin>>A;
            if(A==-1||A==1)continue;
            ans+=c[A][1];
        }
    }
    cout<<ans<<"\n";
    return 0;
}

