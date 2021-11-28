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
typedef unsigned long long ull;
typedef pair<int, int> P;
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1000000;
static const int NMAX=50;
static const int MMAX=50;
int n;
ull A[MAX];
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>n;
    
    A[0]=0; A[1]=0; A[2]=1;
    
    for(int i=3;i<n;i++){
        A[i]=(A[i-3]+A[i-2]+A[i-1])%10007;
    }
    cout<<A[n-1]<<"\n";
    return 0;
}
