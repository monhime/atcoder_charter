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
    cin.tie(0);  ios::sync_with_stdio(false);
    
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='o'||s[i]=='k'||s[i]=='u')continue;
        else if(s[i]=='c'&&s[i+1]=='h'){
            i++; 
            continue;
        }else{
            cout<<"NO"<<"\n";
            return 0;
        }
    }
    cout<<"YES"<<"\n";
    return 0;
}

