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
static const int MAX=100000;
int N,C,s,t,c,cunt;
typedef pair<int,pair<int,int> > P;
vector<P> list;
vector<int> flag[MAX];//時間に録画機の番号
int max_sum,sum_flag[MAX];


void solve(){
    for(int i=0;i<N;i++){
        int p1=list[i].first;
        int p2=list[i].second.first;
        int p3=list[i].second.second;
            for(int k=0;k<flag[p2-1].size;k++){
                if(flag[p2-1][k]==p1){
                    flag[p2][j]=flag[p2-1][j];
                    break;
                }    
            }
        }    
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<30;j++){
            sum_flag[i]+=flag[j][i];
        }
        if(max_sum<sum_flag[i])
            max_sum=sum_flag[i];
    }
}
int main(){
    cin>>N>>C;
    for(int i=0;i<N;i++){
        cin>>s>>t>>c;
        list.push_back(P(c,make_pair(s,t)));
    }
    solve();
    cout<<max_sum<<"\n";

    return 0;
}

