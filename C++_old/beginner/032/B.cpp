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
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map <string,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;

int main(){
    string s; int k; cin>>s>>k;
    
    if(s.size()<k){
        cout<<0<<"\n";
        return 0;
    }
    for(int i=0;i<s.size()-k+1;i++){
        string ss="";
        for(int j=0;j<k;j++){
            ss+=s[i+j];
        }
        mp[ss]++;
    }

    cout<<mp.size()<<"\n";

    return 0;
}


