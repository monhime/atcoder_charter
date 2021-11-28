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
static const ll MAX=1000000000;
static const int NMAX=200;
int N;
int ans=INF;
ll a;

int cunt2(ll n){
    int cunt=0;
    while(!(n%2)){
        n/=2;
        cunt++;
    }
    return cunt;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a;
        ans=min(ans,cunt2(a));
    }

    cout<<ans<<"\n";

    return 0;
}

