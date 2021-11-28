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
static const int NMAX=50;
static const int MMAX=50;
ll ans=1ll;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    int  N,M; cin>>N>>M;
    
    if(abs(N-M)>1){
        cout<<0<<"\n";
        return 0;
    }
    
    for(int i=1;i<=N;i++){
        ans=(ans*i)%((int)pow(10,9)+7);
    }
    for(int i=1;i<=M;i++){
        ans=(ans*i)%((int)pow(10,9)+7);
    }
    
    cout<<(N==M?(2*ans)%((int)pow(10,9)+7):ans)<<"\n";
    
    return 0;
}










