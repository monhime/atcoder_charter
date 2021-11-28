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
int N,S,T,a,w;

int main(){
    cin>>N>>S>>T;
    int cunt=0;
    for(int i=0;i<N;i++)
    {
        cin>>a;
        w+=a;
        if(w>=S&&w<=T)cunt++;
     }
     cout<<cunt<<"\n";
    return 0;
}

