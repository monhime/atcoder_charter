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
int N;
ll T[2],A[2],k1,k2;
ll sum;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;
    cin>>T[0]>>A[0];
    N--;
    while(N--){
        cin>>T[1]>>A[1];
        
        k1=(T[0]%T[1]?T[0]/T[1]+1:T[0]/T[1]);
        k2=(A[0]%A[1]?A[0]/A[1]+1:A[0]/A[1]);
        
        
        T[1]*=max(k1,k2);
        A[1]*=max(k1,k2);
        
        swap(T[0],T[1]); swap(A[0],A[1]);
    }
    
    cout<<T[0]+A[0]<<"\n";
    return 0;
}
