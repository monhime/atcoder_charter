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
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;

char A[3][3];
int b[2][3],c[2][3];

int calc(){
    int score = 0;
    
    for(int i=0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(A[i][j] == A[i+1][j]) score += b[i][j];
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            if(A[i][j]==A[i][j+1]) score+=c[i][j];
        }
    }
    return score;
}


int dfs(int turn){ //state 0:大 1:子
    if(turn==9) return calc();
    
    if(turn%2==0){
        int Max=-1;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(A[i][j]!='*') continue;
                A[i][j]='o';
                Max=max(Max,dfs(turn+1));
                A[i][j]='*';
            }
        }
        return Max;
    }else{
        int Min=INF;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(A[i][j]!='*')continue;
                A[i][j]='x';
                Min=min(Min,dfs(turn+1));
                
                A[i][j]='*';
            }
                
        }
        return Min;
    }
}


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    int sum = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++) {
            cin >> b[i][j]; sum += b[i][j];
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cin >> c[i][j]; sum += c[i][j];
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) A[i][j]='*';
    }
    
    int chokudai=dfs(0);
    
    cout<<chokudai<<"\n";
    cout<< sum - chokudai <<"\n";
    
    
    return 0;
}
