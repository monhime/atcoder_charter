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
int strength[14]={-1,13,1,2,3,4,5,6,7,8,9,10,11,12};
int main(){
    int A,B;
    cin>>A>>B;

    if(strength[A]>strength[B])cout<<"Alice"<<"\n";
    else if(strength[A]<strength[B])cout<<"Bob"<<"\n";
    else cout<<"Draw"<<"\n";

    return 0;
}

