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

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    string s; int N;
    cin>>N>>s;

    if(!(N%2)||s[s.size()/2]!='b'){
        cout<<-1<<"\n";
        return 0;
    }

    for(int i=1;i<s.size()/2;i++){
       char s1=s[s.size()/2-i];
       char s2=s[s.size()/2+i];

       if(i%3==1){
            if(s1=='a'&&s2=='c')continue;
            else {
                cout<<-1<<"\n";
                return 0;
            }    
       }else if(i%3==2){
            if(s1=='c'&&s2=='a')continue;
            else{
                cout<<-1<<"\n";
                return 0;
            }
       }else{
            if(s1=='b'&&s2=='b')continue;
            else{
                cout<<-1<<"\n";
                return 0;
            }
       }
    }

    cout<<N/2<<"\n";

    return 0;
}


