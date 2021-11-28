#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX=100000;
int N,a,b;
ll K,aa[MAX+1];
int main(){
    cin>>N>>K;

    while(N--){
        cin>>a>>b;
        aa[a]+=b;
    }
    for(int ans=1;ans<=MAX;ans++){
        K-=aa[ans];
        if(K<=0){
            cout<<ans<<"\n";
            break;
        }
    }
    return 0;

}

