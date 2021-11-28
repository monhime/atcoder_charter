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
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    char c[4][4];
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)cin>>c[i][j];
    }
    for(int i=3;i>=0;i--){
        for(int j=3;j>=0;j--)cout<<(j==3?"":" ")<<c[i][j];
        cout<<"\n";
    }
    return 0;
}
