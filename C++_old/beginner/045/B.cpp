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
typedef pair<int, int> P;
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
queue<char> Qa,Qb,Qc;

int main(){
    string sa,sb,sc;cin>>sa>>sb>>sc;
    for(int i=0;i<sa.size();i++)Qa.push(sa[i]);
    for(int i=0;i<sb.size();i++)Qb.push(sb[i]);
    for(int i=0;i<sc.size();i++)Qc.push(sc[i]);

    char flag='a',winner; 
    while(1){
        if(flag=='a'){
            if(Qa.empty()){
                cout<<'A'<<"\n"; break;
            }    
            flag=Qa.front(); Qa.pop();
        }
        else if(flag=='b'){
            if(Qb.empty()){
                cout<<'B'<<"\n";break;
            }    
            flag=Qb.front(); Qb.pop();
        }    
        else if(flag=='c'){
            if(Qc.empty()){
                cout<< 'C'<<"\n"; break;
            }    
            flag=Qc.front(); Qc.pop();
        }    
   }

    return 0;
}


