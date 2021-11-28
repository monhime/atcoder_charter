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
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <string,int> mp;
vector<int> V;
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
string s;
int k;


void solve(){
    for(int l=1;l<=s.size();l++){//部分文字列の長さ
        for(int i=0;i<s.size();i++){ //i番目からの部分文字列
            if(i+l-1>=s.size())break;
            string ss="";
            for(int j=0;j<l;j++){
                ss+=s[i+j];
            }
            mp[ss]++;
        }
    }
    
    int cunt=0;
    for(auto p: mp){
        if(cunt==k-1) cout<<p.first<<"\n";
        cunt++;
    }
 }

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>s>>k;
    
    solve();

    return 0;
}
