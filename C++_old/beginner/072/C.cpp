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
int N,x,cunt[MAX+1],X[MAX+1],max_p;
int a[3]={-1,0,1};
int main(){
    cin>>N;
    vector<int>V[N];
    
    for(int i=1;i<=N;i++){
        cin>>x;
        for(int j=0;j<3;j++)
            mp[x+a[j]]++;
    }
    
    for(auto p:mp){
        max_p=max(max_p,p.second);
    }

    cout<<max_p<<"\n";

    return 0;
}

