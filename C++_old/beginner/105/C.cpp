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
#define INFLL (1ll<<62)
#define EPS (1e-10)
static const int MAX=(int) 1e5;
static const int MOD=(int) 1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
bool XOR(int a,int b){ return !a != !b; }
ll N;


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N;
    ll res;
    for(ll mask=0ll;mask<INFLL;mask++){
        res = 0ll;
        string s="";
        for(int i=0;i<62;i++){
            if((mask>>i)&1) {
                res+=(1<<i) * (i%2?-1ll:1);
                s="1"+s;
            }else s="0"+s;
        }
        if(res == N){
            int  flag;
            for(int i=0;s.size();i++){
                if(s[i]=='1'){
                    flag=i;
                    break;
                }
            }
            for(int i=flag;i<s.size();i++) cout << s[i];
            cout <<"\n";
            return 0;
        }
    }
    
    return 0;
}

