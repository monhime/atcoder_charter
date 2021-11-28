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
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int a[5];
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    for(int i=0;i<5;i++) cin>>a[i];
    
    if(a[0]+a[3]>=a[1]+a[2])cout<<a[0]+a[3]+a[4]<<"\n";
    else cout<<a[1]+a[2]+a[4]<<"\n";
    
    return 0;
}
