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
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e4;
static const int MOD=1e9+7;
static const int KMAX=100;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,D,K,L[MAX+1],R[MAX+1],S[KMAX+1],T[KMAX+1];
int  ans[KMAX+1];
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>D>>K;
    for(int i=1;i<=D;i++) cin>>L[i]>>R[i];
    for(int i=1;i<=K;i++) cin>>S[i]>>T[i];
    
    for(int day=1;day<=D;day++){
        for(int k=1;k<=K;k++){
            if(ans[k])continue;
            
            if(L[day]<=S[k]&&S[k]<=R[day]){//動ける
               if(L[day]<=T[k]&&T[k]<=R[day])//ゴールにつける
                ans[k]=day;
               else if(S[k]<T[k]) S[k]=R[day];
               else S[k]=L[day];
            }
        }
    }
    
    for(int k=1;k<=K;k++) cout<<ans[k] << "\n";
    
    
    return 0;
}
