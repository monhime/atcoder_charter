#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
int height[1000],a,b;

void solve(){
    height[0]=0;
    for(int i=1;i<1000;i++)
        height[i] = height[i-1]+i;
    
    cout <<height[b-a]-b <<"\n";
}

int main(){
    cin >> a >> b;
    
    solve();
    return 0;
}
