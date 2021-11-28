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
int N,T,a[MAX];
ll sum;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>T;
    cin>>a[0];
    for(int i=1;i<N;i++){
       cin>>a[i];
       if(a[i]>=a[i-1]+T)sum+=T;
       else sum+=a[i]-a[i-1];
    }
    cout<<sum+T<<"\n";
    return 0;
}


