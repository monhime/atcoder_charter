#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<deque>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
map<int,int> mp_c,mp_r; //行、列にある飴の個数
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int r[MAX+1],c[MAX+1],rr[MAX+1],cc[MAX+1],R,C,K,N;
ll cunt;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>R>>C>>K>>N;
    
    for(int i=1;i<=N;i++){ //飴のある座標の入力、行、列にある飴の数をカウント
        cin>>r[i]>>c[i];
        rr[r[i]]++; cc[c[i]]++;
    }
    
    for(int i=1;i<=R;i++) mp_r[rr[i]]++;//行の飴の個数の表
    for(int i=1;i<=C;i++) mp_c[cc[i]]++;//列の飴の個数の表
    
    for(int i=0;i<=K;i++)
        cunt+=mp_r[i]*mp_c[K-i];//和がKとなるマスの個数？
    
    for(int i=1;i<=N;i++){//飴のある場所を調整
        if(rr[r[i]]+cc[c[i]]==K) cunt--;
        else if(rr[r[i]] + cc[c[i]] == K+1) cunt++;
    }
    cout << cunt << "\n";
    
    return 0;
}

