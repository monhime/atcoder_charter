#include "bits/stdc++.h"
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
static const int NMAX=50;
static const int MMAX=50;
ll N,T,t1,t2,sum;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>T;
    
    for(int i=0;i<N;i++){
        cin>>t2;
        if(t1+T<=t2)sum+=T;
        else sum+=t2-t1;
        t1=t2;
    }
    cout<<sum+T<<"\n";
    
    return 0;
}
