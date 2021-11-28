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
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,win,lose;
string s;

int  solve(){
    int cunt_p=0,cunt_g=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='g'){
            if(cunt_p<cunt_g){
                cunt_p++; win++;
            }else cunt_g++;
        }else{
            if(cunt_p<cunt_g){
                cunt_p++;
            }else{
                cunt_g++; lose++;
            }
        }
    }
    
    return win-lose;
    
}
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);

    cin>>s;
    
    cout<<solve()<<"\n";
    
    
    return 0;
}
