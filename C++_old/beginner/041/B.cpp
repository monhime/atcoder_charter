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
static const ll NINE_POW=1e9;
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
ll A,B,C;
int main(){
    cin>>A>>B>>C;

    cout<<(A*B)% (NINE_POW+7)  *C % (NINE_POW+7)<<"\n";

    return 0;
}


