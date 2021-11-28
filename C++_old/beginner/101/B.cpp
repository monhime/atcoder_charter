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
static const int NMAX=50;
static const int MMAX=50;
int S;
string N;

class number{
    int x=0;
    string N;
public:
    int count_each_digit(string N){
        for(int i=0;i<N0.size();i++) x += N0[i] -'0';
        return x;
    }
}

void solve(){
    //for(int i=0;i<N.size();i++) S += N[i] - '0';
    S = count_each_digit(N);
    if(stoi(N) % S) cout <<"No"<<"\n";
    else cout <<"Yes"<<"\n";
}

int main(){
    cin >> N;
    solve();
    return 0;
}
