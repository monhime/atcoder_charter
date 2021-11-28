#include<iostream>
using namespace std;
static const int MAX=100001;
static const int NIL=-1;

typedef struct Node{
    int p,l,r;
}Node;

Node T[MAX];
int n,D[MAX];

void print(int u){
    int i,c;
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<T[u].p<<", ";
    cout<<"depth = "<<D[u]<<", ";

    if(T[u].p==NIL)cout<<"root, ";
    else if(T[u].l==NIL)cout<<"leaf, ";
    else cout<<"internal node, ";

    cout<<"[";
    c=T[u].l;
    for(int i=0;c!=NIL;i++){
        if(i)cout<<", ";
            cout<<c;
            c=T[c].r;
    }
    
    
    cout<<"]"<<"\n";
}
void rec(int u,int p){
    D[u]=p;
    if(T[u].r!=NIL)rec(T[u].r,p);
    if(T[u].l!=NIL)rec(T[u].l,p+1);
}
int  main(){
    int id,k,c,l,r;
    cin>>n;
    for(int i=0;i<n;i++)T[i].p=T[i].l=T[i].r=NIL;
    for(int i=0;i<n;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            cin>>c;
            if(j==0)T[id].l=c;
            else  T[l].r=c;
            l=c;
            T[c].p=id;
                       
                
        }
    }
    for(int i=0;i<n;i++){
        if(T[i].p==NIL)
            r=i;
    }
    rec(r,0);
    for(int i=0;i<n;i++)
        print(i);
    return 0;    
}
