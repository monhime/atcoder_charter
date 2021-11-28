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
int  m;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>m;
    
    if(m<100)cout<<"00"<<"\n";
    else if(m<=5000)printf("%.2d\n",m/100);
    else if(m<=30000)cout<<m/1000+50<<"\n";
    else if(m<=70000)cout<<((m-30000)/5000+80)<<"\n";
    else cout<<89<<"\n";
    
    
    return 0;
}
