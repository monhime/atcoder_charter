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
int group[13]={0,1,3,1,2,1,2,1,1,2,1,2,1};
int main(){
    int x,y;
    cin>>x>>y;
    if(group[x]==group[y])cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";

    return 0;
}

