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
    int X,A,B;

    cin>>X>>A>>B;

    if(B<=A)cout<<"delicious"<<"\n";
    else if(B-A<=X)cout<<"safe"<<"\n";
    else cout<<"dangerous"<<"\n";

    return 0;
}

