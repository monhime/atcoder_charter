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
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
int cunt[MAX+2],N; //i円引き出すのにcount[i]回必要

//x以下のｎの累乗の最大値を返す
class number{
    int N,cunt,ans;
public:
    number(int n,int c){ N=n,cunt=c,ans=1;}
    
    int ruizyo_max(){
        while(1){ //return時のcunt-1 = 指数
            if(ans > N) return ans/N;
            ans *= N;
            cunt++;
        }
    }
};

void solve(){
    for(int i=1;i<=MAX;i++) cunt[i] = i; //1円だけ
    
    for(int i=6;i<=MAX;i++){
        for(int j=6;j<=i;j*=6){
            if(cunt[i] > cunt[i-j] + 1)  cunt[i] = cunt[i-j] + 1;
        }
    }
    for(int i=9;i<=MAX;i++){
        for(int j=9;j<=i;j*=9){
            if(cunt[i] > cunt[i-j] + 1)  cunt[i] = cunt[i-j] + 1;
        }
    }
    cout << cunt[N] <<"\n";
}

int main(){
    cin >> N;
    solve();
    number num(124,11);
    cout<<num.ruizyo_max()<<"\n";
    return 0;
}
