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
map <int,int> mp;

#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=20;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int a,N;
vector<int> Sub[MAX+1];

int dfs(int v){
    if(Sub[v].empty()) return 1;
    if(Sub[v].size()==1) return 2*dfs(Sub[v][0])+1;
    int max_money=-INF,min_money=INF,money,sum_money=0;
    for(auto it=Sub[v].begin();it!=Sub[v].end();it++){
        money=dfs(*it);
        max_money=max(max_money,money);
        min_money=min(min_money,money);
        
        sum_money=max_money+min_money+1;
        
    }
    return sum_money;
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N;
    for(int i=2;i<=N;i++){
        cin>>a;
        Sub[a].push_back(i);
    }
    
    cout<<dfs(1)<<"\n";
    
    
    return 0;
}
