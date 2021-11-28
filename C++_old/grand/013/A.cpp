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
#include<sstream>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
#define debug(x) cerr << #x << ": " << x << "\n";
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=(int) 1e5;
static const int MOD=(int) 1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N;
ll A[MAX+2],d;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N >> A[0];
    int ans=0,status=0;
    //status==0:0が続いてわからない
    for(int i=1;i<N;i++){
        cin >> A[i];
        d = A[i] - A[i-1];
        if(d>0){
            if(status==-1) {ans++;status=0;}
            else status=1;
        }else if(d<0){
            if(status==1) {ans++; status=0;}
            else status=-1;
        }
    }
    cout << ans+1 <<"\n";
    
    return 0;
}
