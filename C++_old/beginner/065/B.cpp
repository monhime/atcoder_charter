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
static const int NMAX=100;
vector <int> a;
int cunt;
int main(){
    int N;
    cin>>N;
    
    a.push_back(-1);

    int ac;
    for(int i=1;i<=N;i++){
        cin>>ac;
        a.push_back(ac);
    }
    int c=1;
    while(c!=2){
         c=a[c];
         cunt++;
         if(c==1||cunt>N){
            cout<<-1<<"\n"; 
            return 0;
         } 
    }
    cout<<cunt<<"\n";

    return 0;

}

