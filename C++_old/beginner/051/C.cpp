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
int sx,sy,tx,ty;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>sx>>sy>>tx>>ty;
    int dy=ty-sy;
    int dx=tx-sx;
    
    for(int i=0;i<dy;i++)cout<<'U';
    for(int i=0;i<dx;i++)cout<<'R';
    for(int i=0;i<dy;i++)cout<<'D';
    for(int i=0;i<dx;i++)cout<<'L';
    cout<<'L';
    for(int i=0;i<dy+1;i++)cout<<'U';
    for(int i=0;i<dx+1;i++)cout<<'R';
    cout<<'D';
    cout<<'R';
    for(int i=0;i<dy+1;i++)cout<<'D';
    for(int i=0;i<dx+1;i++)cout<<'L';
    cout<<'U'<<"\n";;
    
    
    return 0;
}
