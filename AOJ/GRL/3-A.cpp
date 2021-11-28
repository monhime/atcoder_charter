#include<iostream>
#include<vector>
#include<set>
using namespace std;

static const int MAX=100000;

vector<int> G[MAX];
int N;
bool visited[MAX];
int prenum[MAX],parent[MAX],lowest[MAX],timer;

void dfs(int current,int prev){
    prenum[current]=lowest[current]=timer;
    timer++;

    visited[current]=true;
    int next;
    for(int i=0;i<G[current].size();i++){
        next=G[current][i];
        if(!visited[next]){
            parent[next]=current;
            dfs(next,current);
            lowest[current]=min(lowest[current],lowest[next]);
        }else if(next!=prev){
            lowest[current]=min(lowest[current],prenum[next]);
        }
    }
}

void art_points(){
    for(int i=0;i<N;i++) visited[i]=false;
    timer =1;
    dfs(0,-1);
    set<int> ap;
    int np=0;
    for(int i=1;i<N;i++){
        int p=parent[i];
        if(p==0)np++;
        else if(prenum[p]<=lowest[i])ap.insert(p);
    }
    if(np>1) ap.insert(0);
    for(set<int>::iterator it=ap.begin();it!=ap.end();it++)
        cout<<*it<<"\n";
}
int main(){
    int m;
    cin>>N>>m;
    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    art_points();
    return 0;
}
    

