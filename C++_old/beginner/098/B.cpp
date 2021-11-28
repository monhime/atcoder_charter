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
map <char,int> mp;
vector<int> V;
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
bool flag[30];
int cunt[101],cc[101];
string s;

void solve(){
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    for(int i=0;i<s.size();i++){
        
        if(mp[s[i]]==1&&!flag[s[i]-'a']){
            cc[i]=cc[i-1];
            continue;
        }
        mp[s[i]]--;
        if(mp[s[i]]>0&&!flag[s[i]-'a'])cunt[i]=1;
        else if(mp[s[i]]==0) cunt[i]=-1;
        flag[s[i]-'a']=true;
        if(i==0){
            cc[0]=cunt[0];
            continue;
        }
        cc[i]=cunt[i]+cc[i-1];
    }

    int max_n=-INF;
    for(int i=0;i<s.size();i++){
        max_n=max(max_n,cc[i]);
    }
    cout<<max_n<<"\n";
}
    
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    int n;
    cin>>n>>s;
    
    solve();
    
    return 0;
}
