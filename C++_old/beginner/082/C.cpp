#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
ll  a[MAX];
ll N,cunt;

int main(){
    cin>>N;

    for(ll i=0ll;i<N;i++){
        cin>>a[i];
    }
    sort(a,a+N);
    
    ll i=0;
    while(i<N){

        ll tmp=a[i];

        ll j=0;
        for(j=0ll;j<tmp&&i+j<N;j++){//jは判定前の値   
            if(a[i+j]==tmp&&i+j!=N-1)continue;
            if(i+j==N-1){
                cunt+=j+1;
                goto B;
            }
            else {
                cunt+=j;
                break;
            }
        }

        i+=j;//次
        ll k=0;
        
        if(a[i]==tmp){
            for(k=0ll;a[i+k]==tmp&&i+k<N;k++)
                cunt++;
        }

        i+=k;
        cout<<i<<" "<<cunt<<"\n";
    }
    B:;
    cout<<cunt<<"\n";

    return 0;
}

