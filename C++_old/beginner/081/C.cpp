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
int N,K,a,cunt;
 
int main(){
    cin>>N>>K;

    map<int,int> mp;

    for(int i=0;i<N;i++){
        cin>>a;
        mp[a]++;    
    }
    
    priority_queue<int> PQ;

    for(auto p:mp){
        PQ.push(p.second);
    }

    for(int k=0;k<K&&!PQ.empty();k++) PQ.pop();

    if(PQ.empty()) {
        cout<<0<<"\n";
        return 0;
    }

    while(!PQ.empty()){
        cunt+=PQ.top();
        PQ.pop();
    }    

    cout<<cunt<<"\n";

    return 0;
}

