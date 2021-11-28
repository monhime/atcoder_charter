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
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
ll L[86];
int main(){
    L[0]=2;
    L[1]=1;
    for(int i=2;i<=86;i++)
        L[i]=L[i-1]+L[i-2];
    int N;    
    cin>>N;    
    cout<<L[N]<<"\n";    
    return 0;
}

