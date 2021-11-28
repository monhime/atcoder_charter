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
    int c[3];
    cin>>c[0]>>c[1]>>c[2];
    sort(c,c+3);
    if((c[0]==c[1]||c[1]==c[2])&&c[0]!=c[2])
        cout<<2<<"\n";
    else if(c[0]==c[1]&&c[1]==c[2])
        cout<<1<<"\n";
    else cout<<3<<"\n";    
    return 0;
}

