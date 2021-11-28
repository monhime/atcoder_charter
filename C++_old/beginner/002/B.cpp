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

char s_vowel[5]={'a','i','u','e','o'};

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    string s,s1=""; cin>>s;
    
    for(int i=0;i<s.sizew();i++){
        bool flag=false;
        for(int j=0;j<5;j++){
            if(s[i]==s_vowel[j]) flag=true;
        }
        if(flag)continue;
        s1+=s[i];
    }
    cout<<s1<<"\n";
    
    return 0;
}
