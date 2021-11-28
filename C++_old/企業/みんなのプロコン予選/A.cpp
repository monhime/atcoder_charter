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
string s;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>s;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    if(mp['a']==1&&mp['y']==1&&mp['h']==1&&mp['o']==2) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    
    return 0;
}
