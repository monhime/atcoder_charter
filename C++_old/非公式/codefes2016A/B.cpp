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
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,a[MAX+2];
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=1;i<=N;i++) cin>>a[i];
    
    int cunt=0;
    for(int i=1;i<=N;i++){
        if(i==a[a[i]]) cunt++;
    }
    
    cout<<cunt/2<<"\n";
    return 0;
}
