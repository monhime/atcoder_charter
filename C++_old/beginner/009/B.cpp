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
int N,a;q

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a;
        mp[a]++;
    }
    int max1=0,max2=0;
    for(auto p:mp){
        if(max1<p.first){
            max2=max1;
            max1=p.first;
        }
    }
    cout<<max2<<"\n";
    
    return 0;
}
