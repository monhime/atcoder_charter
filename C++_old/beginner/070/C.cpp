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
typedef long long ll;
static const int MAX=100;
int N;
ll T;      
using namespace std;
ll gcd(ll a,ll b){//最大公約数
    if(b==0)return a;
    return gcd(b,a%b);//ユーグリッドの互除法
}
ll lcm(ll a,ll b){//最小公倍数
    ll g=gcd(a,b);
    return a/g*b;
}
int main(){
    cin>>N;
    ll ans=1ll;
    for(int i=0;i<N;i++){
        cin>>T;
        ans=lcm(ans,T);
    }
    cout<<ans<<"\n";
    return 0;
}
