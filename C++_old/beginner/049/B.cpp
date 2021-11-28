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
int H,W;
int main(){
    cin>>H>>W;
    char c[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++)
            cin>>c[i][j];
    }

    for(int i=0;i<2*H;i++){
        for(int j=0;j<W;j++)   
            cout<<c[i/2][j];
        cout<<"\n";
    }

    return 0;
}


