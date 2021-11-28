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
int cunt;
int main(){
    int K,S; cin>>K>>S;

    for(int x=0;x<=K;x++){
        for(int y=0;y<=K;y++){
            if((x+y)<=S&&(x+y)>=S-K)cunt++;
        }
    }
    cout<<cunt<<"\n";
    return 0;
}

