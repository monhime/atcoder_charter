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
static const int MAX=100000;
ll N,cunt_a,cunt_c;
ll A[MAX],B[MAX],C[MAX];
int main(){
    cin>>N;

    for(ll i=0ll;i<N;i++) cin>>A[i];
    for(ll i=0ll;i<N;i++) cin>>B[i];
    for(ll i=0ll;i<N;i++) cin>>C[i];

    sort(A,A+N);
    sort(C,C+N);

    ll ans=0ll;
    for(ll i=0ll;i<N;i++){
        cunt_a=lower_bound(A,A+N,B[i])-A;
        cunt_c=C+N-upper_bound(C,C+N,B[i]);

        ans+=cunt_a*cunt_c;
    }

    cout<<ans<<"\n";

    return 0;
}
