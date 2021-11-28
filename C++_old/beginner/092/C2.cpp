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

int n,x,y,ans;
int cnt[10020];

vector<pair<pair<int, int>, int> > a;
int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        a.push_back(make_pair(make_pair(x,y),0));
    }
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a.push_back(make_pair(make_pair(x,y),1));
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        if(!a[i].second)
            cnt[a[i].first.second]++;
        else{
            for(int j=a[i].first.second-1;j>=0;j--){
                if(cnt[j]){
                    cnt[j]--;
                    ans++;
                    break;
                }
            }
        }    
    }
    cout<<ans<<"\n";
    return 0;
}

