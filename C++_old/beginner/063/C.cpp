//
//  C.cpp
//  
//
//  Created by charter on 2018/05/01.
//

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<deque>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
int N,s,sum,min_s=INF;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s;
        if(s%10&&min_s>s)min_s=s;
        sum+=s;
    }
    
    if(!(sum%10)&&min_s!=INF)sum-=min_s;
    else if(!(sum%10)&&(min_s==INF))sum=0;
    
    cout<<sum<<"\n";
    return 0;
}













