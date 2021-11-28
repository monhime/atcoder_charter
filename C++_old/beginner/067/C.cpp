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
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=200000;
static const int NMAX=50;
static const int MMAX=50;
int N;
ll a[MAX],sum;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;
    cin>>a[0];
    for(int i=1;i<N;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    ll min_d=INFLL;
    
    for(int i=0;i<N-1;i++){
        if(min_d>abs(a[i]-(a[N-1]-a[i]))) min_d=abs(a[i]-(a[N-1]-a[i]));
    }
    
    cout<<min_d<<"\n";
    
    return 0;
}
