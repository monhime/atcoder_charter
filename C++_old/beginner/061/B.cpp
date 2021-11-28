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
static const int NMAX=100;
int N,M;
int main(){
    cin>>N>>M;

    int a,b;
    for(int i=0;i<M;i++){ 
        cin>>a>>b;
        mp[a]++;mp[b]++;
    }
    
    for(int i=1;i<=N;i++){
        cout<<mp[i]<<"\n";
    }

    return 0;
}

