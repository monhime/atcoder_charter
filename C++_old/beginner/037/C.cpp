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
int N,K;
ll a[MAX+1],sum;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>K;
    a[0]=0;
    for(int i=1;i<=N;i++){
        cin>>a[i];a[i]+=a[i-1];
    }
    
    for(int i=K;i<=N;i++)sum+=a[i]-a[i-K];
    cout<<sum<<"\n";
    return 0;
}
