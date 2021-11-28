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
int N,A,B;
ll v[NMAX+1];
ll cunt;

//C[n][k]->nCk
ll C[NMAX+2][NMAX+2];
void comb_table(int N){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=i;j++){
            if(j==0 or j==i){
                C[i][j]=1ll;
            }else{
                C[i][j]=(C[i-1][j-1]+C[i-1][j]);
            }
        }
    }
}

double sum=0.0;
void solve(){
    //一段目の解答

    for(int i=0;i<A;i++) sum+=(double)v[i];
    

    
    //二段目の解答
    int kk1=0,kk2=0;
    for(int i=0;i<N;i++){
        if(v[i]==v[A-1]){
            kk2++; //全体でv[A-1]と同じ個数
            if(i<A) kk1++; //v[0]~v[A-1] でv[A-1]と同じ個数
        }
    }
    
    comb_table(N);
    if(kk1==A){ //v[0]~v[A-1]まで全て同じ
        for(kk1=A;kk1<=B;kk1++)
            cunt+=C[kk2][kk1];
    }else cunt=C[kk2][kk1];
    

    
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>A>>B;
    for(int i=0;i<N;i++) cin>>v[i];
    
    sort(v,v+N,greater<ll>());

    solve();
    
    cout.precision(20);
    cout<<fixed<<sum/A<<"\n";
    cout<<cunt<<"\n";
    return 0;
}
