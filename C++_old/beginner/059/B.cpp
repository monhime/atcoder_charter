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

string A,B;
int main(){
    cin>>A>>B;

    if(A.size()>B.size()) cout<<"GREATER"<<"\n";
    else if(A.size()<B.size()) cout<<"LESS"<<"\n";
    else{
        if(A>B)cout<<"GREATER"<<"\n";
        else if(A==B) cout<<"EQUAL"<<"\n";
        else cout<<"LESS"<<"\n";
    }    

    return 0;
}

