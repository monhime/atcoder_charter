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
static const int MAX=100;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N;
string s;
bool flag[MAX+2]; //)が(とセットならtrue
deque<char> dq;

void check1(int i){
    for(int j=i+1;j<s.size();j++){
        if(s[j]==')'&&!flag[j]) {
            flag[j]=true;
            return;
        }
    }
    dq.push_back(')');
}


void solve(){
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') check1(i);
        else if(!flag[i]) dq.push_front('('); //（とセットでない
    }
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>s;
    
    for(int i=0;i<s.size();i++){
        dq.push_back(s[i]);
    }
    solve();
    
    for(auto itr=dq.begin();itr!=dq.end();itr++){
        cout<<*itr;
    }
    cout<<"\n";
    
    return 0;
}
