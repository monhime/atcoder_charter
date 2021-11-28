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
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int flag;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    string s; cin>>s;
    int i;
    for(i=0;i<s.size();i++){
        if(s[i]!=s[i+1]) continue;

        if(s[i+6]=='B'){//s[i]はミ
            flag=4;
            switch(i){
                case 4:
                    cout<<"Do"<<"\n";
                    break;
                case 2:
                    cout<<"Re"<<"\n";
                    break;
                case 0:
                    cout<<"Mi"<<"\n";
                    break;
            }
        }else{ //s[i]はシ
            flag=12;
            switch(i){
                case 0:
                    cout<<"Si"<<"\n";
                    break;
                case 2:
                    cout<<"La"<<"\n";
                    break;
                case 4:
                    cout<<"So"<<"\n";
                    break;
                case 6:
                    cout<<"Fa"<<"\n";
            }
        }
        break;
        
    }
    return 0;
}
