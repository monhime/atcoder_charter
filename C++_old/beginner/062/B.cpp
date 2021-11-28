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
int H,W;
int main(){
    cin>>H>>W;
    string s[H];
    for(int i=0;i<H;i++) cin>>s[i];

    for(int i=0;i<W+2;i++)cout<<'#';
    cout<<"\n";

    for(int i=0;i<H;i++)
        cout<<'#'<<s[i]<<'#'<<"\n";
    
    for(int i=0;i<W+2;i++)cout<<'#';
    cout<<"\n";


    return 0;
}

