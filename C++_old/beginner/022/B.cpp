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
using namespace std;
typedef long long ll;
typedef pair<int, bool> P;
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    int N;cin>>N;int a,cunt=0;
    for(int i=0;i<N;i++){
        cin>>a;
        if(mp[a]) cunt++;
        else mp[a]=true;
    }
    cout<<cunt<<"\n";                        
    return 0;
}


