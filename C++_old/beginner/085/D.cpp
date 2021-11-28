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
int sum,cunt2,cunt,N,H,a_max;
static const int MAX=10000;
vector<int> a,b;

void solve(){
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<N;i++){
        if(b[i]<a_max)break;
        cunt++;
        sum+=b[i];
        
        if(sum>=H){
            cout<<cunt<<"\n";
            return;
        }    
    }
/*    sort(b.begin(),b.end());
    vector<int>::iterator low_it= lower_bound(b.begin(),b.end(),a_max);      
    for(vector<int>::iterator it=low_it;it<b.end();it++){
        cunt++;
        sum+=*it;
        if(sum>=H){
            cout<<cunt<<"\n";
            return;
        }
    }*/    
    if((H-sum)%a_max)
        cunt2=cunt+(H-sum)/a_max+1;
    else
        cunt2=cunt+(H-sum)/a_max;                 
    cout<<cunt2<<"\n";    
}        

int main(){
    cin>>N>>H;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        if(a_max<x)a_max=x;
        a.push_back(x);
        b.push_back(y);
    }
    solve();
    return 0;
}
