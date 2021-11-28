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
typedef pair<int, int> P;
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;

int main(){
    int h1,h2,w1,w2; cin>>h1>>w1>>h2>>w2;

    if(h1==w2||h1==h2||w1==w2||w1==h2)
        cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";    
    return 0;
}


