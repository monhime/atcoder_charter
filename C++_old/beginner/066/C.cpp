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
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector <int> V;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=200000;
static const int NMAX=50;
static const int MMAX=50;
int n,a;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(i%2)dq.push_back(a);
        else dq.push_front(a);
    }
    
    if(n%2){
        for(auto it=dq.begin();it!=dq.end();it++)
            cout<<(it==dq.begin()?"":" ")<<*it;
    }else{
        for(auto it=dq.end()-1;it>=dq.begin();it--)
        cout<<(it==dq.end()-1?"":" ")<<*it;
    }
    cout<<"\n";
    
    
    return 0;
}
