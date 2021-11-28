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
map <string,int> mp;
vector<string> V;
set<string> set_s;
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int K;
string s;
void solve(){
    for(int i=1;i<=K;i++){ //substringの長さ
        for(int j=0;j<s.size();j++){ //substringの開始位置
            V.push_back(s.substr(j,i));
        }
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    cout<<V[K-1]<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>s>>K;
    solve();
    
    return 0;
}
