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
map <int,bool> mp;
vector<int> V;
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e4;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int K,N,d,n;

map<int,int> mp2;
void cuntDigit(int n){
    mp2.clear();
    while(n){
        mp2[n%10]++;
        n/=10;
    }
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);

    cin>>N>>K;
    for(int i=0;i<K;i++){
        cin>>d;
        mp[d]=true; //嫌いならtrue
    }
    
    int n=1;
    while(1){
        cuntDigit(n);
        bool flag=false;
        for(auto p1:mp2){
            if(mp[p1.first])flag=true; //嫌いリストにあったらtrue
        }
        if(n>=N&&!flag)break;
        n++;
    }
    cout<<n<<"\n";
    
    return 0;
}
