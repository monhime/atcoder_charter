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
bool c[11];
int main(){

    int d;
    for(int i=0;i<3;i++){
        cin>>d;
        if(c[d])c[d]=false;
        else c[d]=true;
    }
    for(int i=1;i<11;i++){
        if(c[i]){
            cout<<i<<"\n";
            return 0;
        }    
    }
    return 0;
}

