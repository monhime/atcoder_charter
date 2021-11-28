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

int main(){
    int A,B,C,K,S,T;
    cin>>A>>B>>C>>K>>S>>T;
    if(S+T>=K)
        cout<<(A-C)*S+(B-C)*T<<"\n";
    else
        cout<<S*A+B*T<<"\n";
    return 0;
}

