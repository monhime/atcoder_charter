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
static const int NMAX=100;
static const int MMAX=100;
bool black[NMAX][MMAX];
int W,H,N;
void paint(int x,int y,int a){
    if(a==1){
        for(int i=0;i<x;i++){
            for(int j=0;j<H;j++)
                black[i][j]=true;
        }
    }else if(a==2){
        for(int i=x;i<W;i++){
            for(int j=0;j<H;j++)
                black[i][j]=true;
        }
    }else if(a==3){
        for(int i=0;i<W;i++){
            for(int j=0;j<y;j++)
                black[i][j]=true;
        }
    }else {
        for(int i=0;i<W;i++){
            for(int j=y;j<H;j++)
                black[i][j]=true;
        }
    }
}

int main(){
    cin>>W>>H>>N;
    int x,y,a;
    for(int i=0;i<N;i++){
        cin>>x>>y>>a;
        paint(x,y,a);
    }

    int cunt=0;
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(!black[i][j])cunt++;
        }
    }
    cout<<cunt<<"\n";
    return 0;
}


