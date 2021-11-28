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
static const int NMAX=50;
static const int MMAX=50;
ll H,W;
ll ans=INFLL;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>H>>W;
    
    if(H%3==0||W%3==0){
        cout<<0<<"\n";
        return 0;
    }else{
        for(int k=0;k<2;k++){
            ans=min(ans,(H/3+1)*W-H/3*W); //割り切れない時必ず最大(H+1)/3,最小H/3
            swap(H,W);
        }
    }
    
    //次は縦＋横二分割
    
    for(int k=0;k<2;k++){
        for(int ha=1;ha<=H;ha++){
            ll a=ha*W;
            ll b=(H-ha)*(W/2);
            ll c=(H-ha)*((W+1)/2);
            ans=min(ans,max(a,max(b,c))-min(a,min(b,c)));
        }
        swap(H,W);
    }
    cout<<ans<<"\n";
    return 0;
}












