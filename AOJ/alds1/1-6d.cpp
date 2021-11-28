#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX=1000;
static const int VMAX=10000;

int n,A[MAX],s;
int B[MAX],T[VMAX+1];

int solve(){
    int ans=0;
    bool V[MAX];
    for(int i=0;i<n;i++){
        B[i]=A[i];
        V[i]=false;
    }
    sort(B,B+n);    
    for(int i=0;i<n;i++)T[B[i]]=i;
    for(int i=0;i<n;i++){
        if(V[i])continue;
        int S=0;
        int cur=i;
        int m=VMAX;
        int an=0;
        while(1){
            V[cur]=true;
            an++;
            m=min(m,A[cur]);
            S+=A[cur];
            cur=T[A[cur]];
            if(V[cur])break;
        }
        ans+=min(S+(an-2)*m,m+S+(an+1)*s);
    }
    return ans;

}
int main(){
    cin>>n;
    s=VMAX;
    for(int i=0;i<n;i++){
        cin>>A[i];
        s=min(s,A[i]);
    }
    int ans=solve();
    cout<<ans<<"\n";
    return 0;
}

