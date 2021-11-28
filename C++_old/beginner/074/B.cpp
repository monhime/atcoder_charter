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
static const int NMAX=100;

int N,K;
int x[NMAX];

int main(){
    cin>>N>>K;

    for(int i=0;i<N;i++)
        cin>>x[i];
    int ans=0;    
    for(int i=0;i<N;i++)
        ans+=min(2*x[i],2*(K-x[i]));
        
    cout<<ans<<"\n";    
    return 0;
}

