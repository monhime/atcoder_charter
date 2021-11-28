#include<iostream>
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
int main(){

    int n,a,b,q;
    int t;
    cin>>n>>q;
    DisjoinSet ds=DisjoinSet(n);
    for(int i=0;i<q;i++){
        cin>>t>>a>>b;
        if(t==0)ds.unite(a,b);
        else if(t==1){
            if(ds.same(a,b))cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }
    return 0;
}
    
