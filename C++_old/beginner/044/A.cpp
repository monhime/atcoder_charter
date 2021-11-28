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
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;

int main(){
    int N,K,X,Y;
    cin>>N>>K>>X>>Y;
    int cost=0;
    int i;
    for( i=1;i<=K&&i<=N;i++){
        cost+=X;
    }
    for( i=K+1;i<=N;i++)
        cost+=Y;
    cout<<cost<<"\n";    
    return 0;
}

