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
int N,A,B,d,sum;
int main(){
    string s;
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>A>>B;
    for(int i=0;i<N;i++){
        cin>>s>>d;
        if(s[0]=='E')sum+=(d>=A?min(d,B):A);
        else sum-=(d>=A?min(d,B):A);
    }
    if(sum<0)cout<<"West"<<" ";
    else if(sum>0)cout<<"East"<<" ";
    

    cout<<abs(sum)<<"\n";
    return 0;
}


