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
    int cunt =1;
    for(int i=0;i<3;i++)cin>>a[i];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i]<a[j])cunt++;
        }
        cout<<cunt<<"\n";
        cunt=1;
    }
    return 0;
}

