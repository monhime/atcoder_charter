#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
//#include <bits/stdc++.h>
using namespace std;
static const int INF=100000;
static const int MAX=50;
pair<int, int> red[MAX],blue[MAX] ;
int max_score,score,N;
int red_d[MAX],blue_d[MAX];

void dfs(){
    
    for(int i=0;i<N;i++){
        if(red_d[i])continue;
        red_d[i]=1;
        for(int j=0;j<N;j++){
            if(blue_d[j])continue;
            
            if(red[i].first>=blue[j].first||
                red[i].second>=blue[j].second)continue;
            blue_d[j]=1;    
            score++;
            dfs();
            blue_d[j]=0;
        }
        red_d[i]=0;
    }
    if(max_score<score)max_score=score;
    score--;
}
int main(){

    
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>red[i].first>>red[i].second;
    for(int i=0;i<N;i++)
        cin>>blue[i].first>>blue[i].second;
    
    dfs();
    cout<<max_score<<"\n";

    return 0;
}

