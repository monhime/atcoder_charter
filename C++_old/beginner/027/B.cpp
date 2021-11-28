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
    int N;
    cin>>N;int a[N+1];a[0]=0;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        a[i]+=a[i-1];    
    }   

    if(a[N]%N){
        cout<<-1<<"\n";
        return 0;
    }

    int pp=a[N]/N;
    int sum1=0,cunt_bridge=0;
    for(int i=1;i<N;i++){    
        if(a[i]!=pp*i)
            cunt_bridge++;
    }

    cout<<cunt_bridge<<"\n";
    return 0;
}


