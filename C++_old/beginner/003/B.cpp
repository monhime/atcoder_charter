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
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
char ss[8]={'a','t','c','o','d','e','r','@'};

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='@'){
            bool flag=false;
            for(int j=0;j<8;j++){
                if(t[i]==ss[j])flag=true;
            }
            if(!flag){
                cout<<"You will lose"<<"\n";
                return 0;
            }
        }
        if(t[i]=='@'){
            bool flag=false;
            for(int j=0;j<8;j++){
                if(s[i]==ss[j])flag=true;
            }
            if(!flag){
                cout<<"You will lose"<<"\n";
                return 0;
            }
        }
        if(s[i]!=t[i]&&!(s[i]=='@'||t[i]=='@')){
            cout<<"You will lose"<<"\n";
            return 0;
        }
        
    }
    cout<<"You can win"<<"\n";
    
    return 0;
}
