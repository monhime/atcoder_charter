#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
using namespace std;

typedef long long ll;
ll X,Y,cunt;

int main(){
    cin>>X>>Y;

    while(Y>=X){
        Y/=2;
        cunt++;
    }
    cout<<cunt<<"\n";

    return 0;
}

