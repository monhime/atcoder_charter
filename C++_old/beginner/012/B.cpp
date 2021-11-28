#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
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
int N;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    int h,m,t;
    cin>>N;
    
    h=N/3600; m=N%3600/60; t=N-h*3600-m*60;
    
    printf("%.2d:%.2d:%.2d\n",h,m,t);
    return 0;
}

