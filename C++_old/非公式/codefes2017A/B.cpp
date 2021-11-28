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
static const int NMAX=1000;
static const int MMAX=1000;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
ll N,M,k;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>M>>k;

    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(j*(M-i)+i*(N-j)==k){
                
                cout<<"Yes"<<"\n";
                return 0;
            }
        }
    }
    cout<<"No"<<"\n";
    return 0;
}
