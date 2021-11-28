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
int n;

int main(){
    cin>>n;
    int root_n=sqrt(n);
    int flag[root_n+1];
    int min_flag=INF,min_flag_num;
    for(int i=1;i<=root_n;i++){
        flag[i]=abs(n/i-i)+n-(n/i)*i;
        if(min_flag>flag[i])min_flag=flag[i];     
    }
    cout<<min_flag<<"\n";

    return 0;
}


