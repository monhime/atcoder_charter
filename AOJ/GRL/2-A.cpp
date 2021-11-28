#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class DisjoinSet{
    public:
        vector<int> rank,p;
        DisjoinSet(){}
        DisjoinSet(int size){
            rank.resize(size,0);
            p.resize(size,0);
            for(int i=0;i<size;i++)
                makeSet(i);
        }
        void makeSet(int x){
            p[x]=x;
            rank[x]=0;

        }
        int findSet(int x){
            if(x!=p[x]) p[x]=findSet(p[x]);
            return p[x];
        }
        bool same(int x,int y){return findSet(x)==findSet(y);}

        void unite(int x,int y){link(findSet(x),findSet(y));}

        void link(int x,int y){
            if(rank[x]>rank[y]) p[y]=x;
            else{
                p[x]=y;
                if(rank[x]==rank[y]) rank[y]++;
            }
        }
};
class Edge{
    public:
        int source,target,cost;
        Edge(int source=0,int target=0,int cost=0):
            source(source),target(target),cost(cost){}
        bool operator < (const Edge &e)const{//sort()で必要
            return cost<e.cost;
        }    
};
int kruskal(int N,vector<Edge> edges){
    int totalCost=0;
    sort(edges.begin(),edges.end());//昇順->自然に最小全域木に
    DisjoinSet dset=DisjoinSet(N+1);
    for(int i=0;i<N;i++)dset.makeSet(i);

    int source,taget;
    for(int i=0;i<edges.size();i++){
        Edge e=edges[i];
        if(!dset.same(e.source,e.target)){//source とtargetが別の集合->閉路にならない
            totalCost+=e.cost;
            dset.unite(e.source,e.target);
        }
    }
    return totalCost;

}
int main(){
    int N,M,cost,source,target;
    cin>>N>>M;
    vector<Edge> edges;
    for(int i=0;i<M;i++){
        cin>>source>>target>>cost;
        edges.push_back(Edge(source,target,cost));
    }
    cout<<kruskal(N,edges)<<"\n";
    return 0;
}

