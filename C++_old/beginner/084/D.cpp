#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
//#include <bits/stdc++.h>
using namespace std;
int Q;
int l,r;
static const int MAX=100000;
bool f[MAX+1];
int c[MAX+2];
void prime(){
    for(int i=2;i<=MAX;i++){
        if(f[i])continue;
        for(int j=i*2;j<=MAX;j+=i){
            f[j]=true;
        }
    }
    for(int i=3;i<=MAX;i+=2){
        if(!f[i]&&!f[(i+1)/2])
            c[i]++;
    }
    for(int i=3;i<=MAX;i++) c[i]+=c[i-1];

}
int main(){
    cin>>Q;
    prime();
    while(Q--){
        cin>>l>>r;
        cout<<c[r]-c[l-1]<<"\n";
    }
    return 0;
}

