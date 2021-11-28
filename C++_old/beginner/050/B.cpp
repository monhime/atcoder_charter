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
typedef long long ll;
static const int MAX=100000;
static const int NMAX=100;
int N,T[NMAX],M,P[NMAX],X[NMAX],sum;

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>T[i];
        sum+=T[i];
    }    
    cin>>M;
    for(int i=0;i<M;i++)cin>>P[i]>>X[i];

    for(int i=0;i<M;i++)
        cout<<sum-(T[P[i]-1]-X[i])<<"\n";
    return 0;
}

