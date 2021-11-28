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
map <char,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
static const int NMAX=100;

int main(){
    string s;
    cin>>s;

    for(int i=s.size()-2;i>=1;i--){
        if(!(i%2))continue;
        int i2=i/2;                    
        bool flag=true;
        for(int j=0;j<=i2;j++){
            if(s[j]!=s[i2+1+j]){
                flag=false; break;
            }    
        }
        
        if(flag) {
            cout<<i+1<<"\n";
            break;
        }    
    }       
    return 0;
}

