#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
static const int NMAX=50;
int N,M;

int main(){
    cin>>N>>M;
    string a[N],b[M];

    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<M;i++) cin>>b[i];

    for(int i=0;i<N-M+1;i++){
        for(int j=0;j<N-M+1;j++){
            if(a[i][j]==b[0][0]){
                for(int k=0;k<M;k++){
                    for(int l=0;l<M;l++){
                        if(a[i+k][j+l]!=b[k][l]){
                            goto A;
                        }
                    }
                }
                cout<<"Yes"<<"\n";
                return 0;
            }
            A:;
        }
    }
    cout<<"No"<<"\n";
    return 0;
}

