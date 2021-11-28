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
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;

int main(){
    string s[12];
    for(int i=0;i<12;i++) cin>>s[i];
    
    int cunt=0;
    for(int i=0;i<12;i++){
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]=='r'){   
                cunt++; break;
            }    
        }
    }
    cout<<cunt<<"\n";

    return 0;
}


