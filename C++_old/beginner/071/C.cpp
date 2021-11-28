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
int N;
int main(){
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a,a+N);

    int s=0,f=0;
    for(int i=0;i<N;i+=2){
        if(a[i]==a[i+1]){
            s=f;
            f=a[i];
        }
        else i--;
    }
    cout<<(long long)s*f<<"\n";
    return 0;
}

