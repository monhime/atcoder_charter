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
vector <int> l;
int N,K,len;

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        
        cin>>len;
        l.push_back(len);
    }

    sort(l.begin(),l.end(),greater<int>());

    
    int ans=0;
    for(int i=0;i<K;i++)
        ans+=l[i];
    cout<<ans<<"\n";
    return 0;
}

