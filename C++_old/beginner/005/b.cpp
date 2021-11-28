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
int n,min_t=INF,t;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>t;
        if(min_t>t)min_t=t;
    }
    cout<<min_t<<"\n";

    return 0;
}
