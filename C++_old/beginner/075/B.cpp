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
static const int MAX=50;
int H,W,cunt[MAX+2][MAX+2];
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
int main(){
    cin>>H>>W;
    string s[H];
    for(int i=0;i<H;i++){
        cin>>s[i];
        for(int j=0;j<W;j++){
            if(s[i][j]=='#'){
                for(int k=0;k<8;k++)
                    cunt[i+1+dx[k]][j+1+dy[k]]++;
            }
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j]=='#')cout<<'#';
            else
                cout<<cunt[i+1][j+1];
        }
        cout<<"\n";
    }

    return 0;
}

