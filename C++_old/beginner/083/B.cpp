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


int N,A,B;
 //各桁の数字の和?
int cunt_digit(int n){   
    int a=0;
    while(n){
        a+=n%10;
        n/=10;
    }

    return a;
}

int main(){

    cin>>N>>A>>B;
    int sum=0;
    for(int i=1;i<=N;i++){
       if(!(cunt_digit(i)>=A&&cunt_digit(i)<=B))continue;
       sum+=i;
    }
    cout<<sum<<"\n";

    return 0;
}

