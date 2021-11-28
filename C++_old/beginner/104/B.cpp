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
string s;

void solve(){
    bool flag = true;
    if(s[0]!='A') flag=false;
    int count=0,spot=0;
    for(int i=2;i<=s.size()-2;i++){
        if(s[i]=='C') {
            count++;
            spot=i;
        }
    }
    debug(flag);
    if(count != 1) flag=false;
    debug(spot);
    for(int i=1;i<s.size();i++){
        if(i != spot && ('A' <= s[i] && s[i] <= 'Z')) flag =false;
    }
    debug(flag);
    if(flag) cout << "AC" << "\n";
    else cout <<"WA" <<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> s;
    solve();
    
    return 0;
}

