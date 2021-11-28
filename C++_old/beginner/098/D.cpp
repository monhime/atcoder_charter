#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<sstream>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=2e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
bool a[MAX+1][21],flag[21];
int N;
ll A[MAX+1];

//123 → 1111011
int in10to2(int binary) {
    int out = 0;
    for (int i = 0; binary > 0; i++) {
        out = out + (binary % 2) * pow(static_cast<int>(10), i);
        binary = binary / 2;
    }
    return out;
}


void func(){
    for(int i=0;i<N;i++){
        int aa=A[i]; //10進数
        string bb=to_string(in10to2(aa));
        
        for(int j=0;j<bb.size();j++){
            if(bb[j]=='1')a[i][j]=1;
        }//逆順で２進数記入
    }
}

void solve(){
    func();
    ll ans=0ll;
    for(int i=0;i<N;i++){ //はじめ
        int j;
        for( j=i;j<N;j++){ //終わり
            for(int k=0;k<21;k++){
                if(a[j][k]==1&&flag[k]==1){
                    memset(flag,0,sizeof(flag));
                    goto A;
                }
            }
            ans++;
            
            for(int k=0;k<21;k++){
                flag[k]=1;
            }
        }
    A:
        i=j-1;
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    
    solve();
    
    return 0;
}
