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
vector<int> V;
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int N,a[MAX];
ll dp[MAX+1];
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<MAX+1;i++)dp[i]=INFLL;
    for(int i=0;i<N;i++)cin>>a[i];
    
    dp[0]=0;
    dp[1]=dp[0]+abs(a[1]-a[0]); //1本目へは+1の１通り
    for(int j=2;j<N;j++) dp[j]=min(dp[j-1]+abs(a[j]-a[j-1]),dp[j-2]+abs(a[j]-a[j-2]));
    
    cout<<dp[N-1]<<"\n";
    return 0;
}
