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
    char c[2][3];

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++)
            cin>>c[i][j];
    }

    
    if(c[0][0]==c[1][2]
        &&c[0][1]==c[1][1]
        &&c[0][2]==c[1][0])
            cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";

    return 0;
}

