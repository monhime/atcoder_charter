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
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a+b>c+d)cout<<"Left"<<"\n";
    else if(a+b==c+d)cout<<"Balanced"<<"\n";
    else cout<<"Right"<<"\n";

    return 0;
}

