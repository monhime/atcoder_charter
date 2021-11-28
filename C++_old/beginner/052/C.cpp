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
static const int MAX=1000;
static const int NMAX=50;
static const int MMAX=50;
int N;

bool f[MAX+1];//篩　iが素数ならf[i]はfalse i
void prime(){
    for(int i=2;i<=MAX;i++){
        if(f[i])continue;
        for(int j=i*2;j<=MAX;j+=i) f[j]=true;
    }
}


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;
    
    prime();
    

    ll ans=1;
    for(int i=2;i<=N;i++){
        int cunt=0;
        if(f[i])continue;
        
        int x=i;
        while(x<=N){
            cunt+=N/x;
            x*=i;
        }
        ans=ans*(cunt+1)%(int)(1e9+7);
        
    }
    cout<<ans%(int)(1e9+7)<<"\n";
    
    return 0;
}
