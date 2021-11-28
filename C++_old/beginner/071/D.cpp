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
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N;
string s1,s2;

void solve(){
    int i;
    bool status; //1:横,0:縦
    ll ans;
    if(s1[0]==s1[1]){ //横
        ans=6ll;
        i=2;
        status = true;
    }else{ //縦
        ans=3ll;
        i=1;
        status = false;
    }
    
    for(;i<s1.size();i++){
        if(s1[i]==s1[i+1]){
            if(status){ //横→横
                ans*=3ll;
                status = true;
            }else{ //縦→横
                ans*=2ll;
                status = true;
            }
            i++;
        }else{
            if(status){ //横→縦
                ans*=1ll;
                status= false;
            }else{ //縦→縦
                ans*=2ll;
                status=false;
            }
        }
        ans %= MOD;
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>s1>>s2;
    solve();
    
    return 0;
}
