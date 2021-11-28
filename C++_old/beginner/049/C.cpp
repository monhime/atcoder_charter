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
static const int MAX=100000;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    string s,s1="erase",s2="dream";
    cin>>s;
    
    for(int i=0;i<s.size();i+=5){ //5文字飛ばし
        
        if(s[i]!='e'&&s[i]!='d'){
            cout<<"NO"<<"\n";
            return 0;
        }
        if(s[i]=='e'){
            for(int j=0;j<5;j++){
                if(i+j==s.size()||s[i+j]!=s1[j]){
                    cout<<"NO"<<"\n";
                    return 0;
                }
            }
            //eraseまで一致
            if(i+5<=s.size()-1&&s[i+5]=='r')i++; //六文字飛ばしさせる
        }else if(s[i]=='d'){
            for(int j=0;j<5;j++){
                if(i+j==s.size()||s[i+j]!=s2[j]){
                    cout<<"NO"<<"\n";
                    return 0;
                }
            }
            //dreamまで一致
            if((i+7<=s.size()-1&&s[i+5]=='e'&&s[i+6]=='r'&&s[i+7]!='a')||(i+6==s.size()-1&&s[i+5]=='e'&&s[i+6]=='r'))i+=2; //六文字飛ばしさせる
        }
        
    }
    cout<<"YES"<<"\n";
    
    return 0;
}
