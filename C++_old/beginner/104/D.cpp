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
#define debug(x) cerr << #x << ": " << x << "\n";
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=(int) 1e6;
static const int MOD=(int) 1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };

int D,G;
int p[11],c[11];
int num;//解く問題数
int score; //得点
int max_rest;//完答しない問題のなかで最大の問題

void solve(){
    int ans = INF;
    for(int mask = 0;mask < (1<<D);mask++){ //完答する問題の2進数表記
        num =0; score=0; //リセット忘れるな！！
        for(int i=0;i<D;i++){
            if((mask >> i) & 1 ){ //i番目を完答する
                num += p[i];
                score += 100 * (i+1) * p[i] + c[i];
            }else{
                max_rest = i;
            }
        }
        if(score<G){
            int s1 =(max_rest+1)*100;
            int need = (G - score + s1 -1) / s1; //切り上げ除算
            if(p[max_rest] <= need) continue;
            num += need;
        }
        ans = min(num,ans);
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> D >> G;
    for(int i=0;i<D;i++) cin >> p[i] >> c[i];
    
    solve();
    
    return 0;
}
