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
    char x[2],y[2];
    cin>>x[0]>>y[0];

    if(x[0]==y[0])cout<<"="<<"\n";
    else if(x[0]<y[0])cout<<"<"<<"\n";
    else cout<<">"<<"\n";

    return 0;
}

