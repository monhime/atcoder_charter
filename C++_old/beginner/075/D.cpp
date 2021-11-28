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
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,M,max_y=-INF,min_y=INF;
priority_queue<P> pq;
vector<P> four_points;
ll min_s=INFLL;
ll S=0ll;

void check(P p){

    int num;
    for(int i=0;i<M;i++){ //iを除いて考える
        for(int j=0;j<M;j++){
            if(i==j)continue;
            P p1=four_points[j];
            max_y=max(max_y,p1.second);
            min_y=min(min_y,p1.second);
        }
        cout<<max_y<<" "<<min_y<<"\n";
        S=(max_y-min_y)*((i==M-1?four_points[M-2].first:four_points[M-1].first));
        
        if(min_s>S){
            num=i;
            min_s=S;
        }
    }
    
    auto itr=four_points.erase(four_points.begin()+num);
    four_points.push_back(p);
    
}

void solve(){

    for(int i=0;i<M;i++){//最初にM個記録
        P p=pq.top(); pq.pop();
        four_points.push_back(p);  //xの大きいものが先頭に来ている
    }
    if(N==M){
        for(int j=0;j<M;j++){
            P p1=four_points[j];
            max_y=max(max_y,p1.second);
            min_y=min(min_y,p1.second);
        }
        min_s=(max_y-min_y)*(four_points[0].first-four_points[M-1].first);
        return;
    }
    for(int i=M;i<N;i++){
        P p=pq.top(); pq.pop();
        check(p);
    }
    
}


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        pq.push(P(x,y));
    }
    
    solve();
    
    cout<<min_s<<"\n";
    
    return 0;
}
