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

P min_p,max_p;
int main(){
    string s; cin>>s;
    int T; cin>>T;
    int cunt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L'){
            min_p.first--;max_p.first--;
        }else if(s[i]=='R'){
            min_p.first++;max_p.first++;
        }else if(s[i]=='U'){
            min_p.second++;max_p.second++;
        }else if(s[i]=='D'){
            min_p.second--;max_p.second--;
        }else cunt++;
    }
    cout<<(T==1?abs(max_p.first)+abs(max_p.second)+cunt:
            max(abs(min_p.first)+abs(min_p.second)-cunt,
                (int )s.size()%2))<<"\n";

    return 0;
}


