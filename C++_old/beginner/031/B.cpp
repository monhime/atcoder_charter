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
int L,H,N,A;
int main(){
    cin>>L>>H>>N;
    for(int i=0;i<N;i++){
        cin>>A;
        if(A>=L&&A<=H)cout<<0<<"\n";
        else if(A>H)cout<<-1<<"\n";
        else cout<<L-A<<"\n";
    }
    return 0;
}


