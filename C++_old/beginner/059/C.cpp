//
//  C.cpp
//  
//
//  Created by charter on 2018/05/02.
//

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
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int NMAX=50;
static const int MMAX=50;
int N,a[MAX];
ll cunt2,cunt1,sum;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    
        sum=0ll;
    //偶数が正
        for(int i=0;i<N;i++){
            if(i%2==0&&sum+a[i]<=0){//sumは負
                cunt1+=(-1)*sum+1-a[i];
                sum=1;
            }else if(i%2!=0&&sum+a[i]>=0){
                cunt1+=a[i]+sum+1;
                sum=-1;
            }else sum+=a[i]; //操作必要なし
            
        }
    //奇数が正
    sum=0ll;
    for(int i=0;i<N;i++){
        if(i%2!=0&&sum+a[i]<=0){
            cunt2+=(-1)*sum+1-a[i];;
            sum=1;
        }else if(i%2==0&&sum+a[i]>=0){
            cunt2+=a[i]+sum+1;
            sum=-1;
        }else sum+=a[i]; //操作必要なし

    }
    
    cout<<min(cunt1,cunt2)<<"\n";
    
    
    return 0;
}

