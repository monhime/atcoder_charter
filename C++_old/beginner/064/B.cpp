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
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
static const int NMAX=100;
vector<int> a;
int main(){
    int N;
    cin>>N;
    int a1;
    for(int i=0;i<N;i++){
        cin>>a1; a.push_back(a1);
    }

    sort(a.begin(),a.end());

    cout<<a[N-1]-a[0]<<"\n";
    return 0;
}

