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
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;

int main(){
    string s;
    cin>>s;
    if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])
        cout<<"SAME"<<"\n";
    else
        cout<<"DIFFERENT"<<"\n";
    return 0;
}

