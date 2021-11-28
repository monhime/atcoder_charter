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
static const int MAX=100000;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int A,B,C,X,Y;
ll cost;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>A>>B>>C>>X>>Y;
    
    
    if(X>=Y&&A>2*C)cost=2*X*C;
    else if(X<Y&&B>2*C)cost=2*Y*C;
    else if(A+B>2*C)cost=2*min(X,Y)*C+(X>Y?(X-Y)*A:(Y-X)*B);
    else cost=A*X+B*Y;
    
    cout<<cost<<"\n";
    
    return 0;
}
