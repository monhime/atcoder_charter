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
    int a[3];

    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);

    if(a[0]==5&&a[1]==5&&a[2]==7)
        cout<<"YES"<<"\n";
    else 
        cout<<"NO"<<"\n";

    return 0;
}

