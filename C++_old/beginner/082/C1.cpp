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
#include<map>
//#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main(){
    int N;
    cin>>N;

    map<int,int> mp;
    
    for(int i=0;i<N;i++)
    
    
    {
        cin>>a[i];
        mp[a[i]]++;
    }

    int ans=0;

    for(auto p: mp)
    {
        int x=p.first;
        int n=p.second;
        
        if(n<x)ans+=n;
        else ans+=n-x;
    }

    cout<<ans<<"\n";

    return 0;
}

