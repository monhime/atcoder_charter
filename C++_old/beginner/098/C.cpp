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
static const int MAX=3e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int cunt_e[MAX+1],cunt_w[MAX+1],cc_e[MAX+1],cc_w[MAX+1];
int n,ans,total_e;
string s;

void solve(){
    
    for(int i=0;i<s.size();i++)if(s[i]=='E')total_e++;
    
    cc_e[0]=0; cc_w[0]=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='E')cunt_e[i]=1;
        else if(s[i]=='W')cunt_w[i]=1;
        
        cc_e[i+1]=cunt_e[i]+(i?cc_e[i]:0);
        cc_w[i+1]=cunt_w[i]+(i?cc_w[i]:0);
    }
    
    int ans=INF;
    
    for(int i=0;i<=s.size();i++){
        int flag_e=total_e-cc_e[i];
        ans=min(ans,flag_e+cc_w[i]);
    }
    
    cout<<ans<<"\n";
}


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>n>>s;
    solve();
    return 0;
}
