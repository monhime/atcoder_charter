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
    int A,B;
    string s;

    cin>>A>>B;
    cin>>s;

    bool flag=1;

    for(int i=0;i<A;i++){
        if(!(s[i]>='0'&&s[i]<='9')){
            flag=0;
            break;
        }    
    }
    if(s[A]!='-')flag=0;

    for(int i=A+1;i<=A+B;i++){
        if(!(s[i]>='0'&&s[i]<='9')){
            flag=0;
            break;
        }    
    }

    cout<<(flag?"Yes":"No")<<"\n";
    
    return 0;
}

