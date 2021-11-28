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
static const int NMAX=1000;
static const int MMAX=50;
int N,R[NMAX+1];
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);

    cin>>N;
    for(int i=0;i<N;i++)cin>>R[i];
    
    sort(R,R+N,greater<int>());

    double ans=0.0;

    for(int i=0;i<N;i++){
        if(!(i%2))ans+=R[i]*R[i];
        else ans-=R[i]*R[i];
    }
    ans*=M_PI;
    printf("%.7f\n",ans);
    return 0;
}


