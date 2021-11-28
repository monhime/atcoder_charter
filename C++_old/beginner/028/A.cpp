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
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;

int main(){
    int N;
    cin>>N;
    if(N<=59)cout<<"Bad"<<"\n";
    else if(N<=89) cout<<"Good"<<"\n";
    else if(N<=99) cout<<"Great"<<"\n";
    else cout<<"Perfect"<<"\n";
    return 0;
}

