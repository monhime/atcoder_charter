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
    cin.tie(0);  ios::sync_with_stdio(false);
    int A,B,C; cin>>A>>B>>C;

    bool flag1=false,flag2=false;

    if(A+B==C)flag1=true;
    if(A-B==C)flag2=true;
     
    if(flag1&&flag2)cout<<'?'<<"\n";
    else if(flag1&&!flag2)cout<<'+'<<"\n";
    else if(!flag1&&flag2)cout<<'-'<<"\n";
    else  cout<<'!'<<"\n";

    return 0;
}


