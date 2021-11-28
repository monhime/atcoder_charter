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
int N;
int main(){
    cin>>N;
    ll cunt=1;
    for(int i=1;i<=N;i++){
        cunt*=i;
        cunt%=(1000000000ll+7);
    }
    cout<<cunt<<"\n";

    return 0;
}

