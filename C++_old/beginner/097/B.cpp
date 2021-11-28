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
int X;
bool table[1001]; //べきならtrue 1ori
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>X;
    table[1]=true;
    
    for(int i=2;i<40;i++){
        for(int j=2;pow(i,j)<=1000;j++){ //iをj乗する
            int x=pow(i,j);
            if(pow(i,j)>1000) break;
            table[x]=true;
        }
    }
    
    for(int i=X;i>=1;i--){
        if(table[i]) {
            cout<<i<<"\n";
            break;
        }
    }
    
    return 0;
}
