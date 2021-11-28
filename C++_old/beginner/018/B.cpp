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
    
    string s;cin>>s;
    int N,l,r; cin>>N;

    for(int i=0;i<N;i++){
        cin>>l>>r; l--; r--;
        string s1="";
        
        for(int j=0;j<l;j++) s1+=s[j];
        for(int j=r;j>=l;j--) s1+=s[j];
        for(int j=r+1;j<s.size();j++) s1+=s[j];

        s=s1;
    }
    cout<<s<<"\n";
    return 0;
}


