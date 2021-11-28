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

bool f[MAX+1];//篩　iが素数ならf[i]はfalse
void prime(){
    for(int i=2;i<=MAX;i++){
        if(f[i])continue;
        for(int j=i*2;j<=MAX;j+=i) f[j]=true;
    }
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    int N;cin>>N;
    prime();
    int p=2;
    for(int i=0;i<N;i++){
        while(1){
            if(f[p]||p%5!=1){
                p++;
                continue;
            }
            cout<<(i?" ":"")<<p;
            p++;
            break;
        }
    }
    cout<<"\n";
    
    return 0;
}
