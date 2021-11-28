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
double m;
double n;
int main(){
    cin>>n>>m;
    if(n>=12.0)n-=12.0;
    n+=m/60.0;
    m/=5.0; 
    double a;
    if(n-m>-EPS) a=min(n-m,12.0+m-n);
    else a=min(m-n,12.0+n-m);

    printf("%.4lf\n",a*30.0);

    return 0;
}


