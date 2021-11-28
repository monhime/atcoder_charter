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
int N,X,sum_m,m,min_m=INF;
int cunt;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>X;
    for(int i=0;i<N;i++){
        cin>>m;
        sum_m+=m;
        if(min_m>m)min_m=m;
    }
    
    cunt+=N;
    
    while(sum_m<=X){
        sum_m+=min_m;
        cunt++;
    }
    
    cout<<cunt-1<<"\n";

    return 0;
}
