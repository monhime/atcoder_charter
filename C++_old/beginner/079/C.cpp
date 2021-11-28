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

int main(){
    int n,a[4];
    cin>>n;
    for(int i=3;i>=0;i--){
        a[i]=n%10;
        n/=10;
    }
    int b;
    for(b=0;b<8;b++){
        int ans=a[0];
        for(int i=0;i<3;i++){
            if(b>>i&1)ans+=a[i+1];
            else ans-=a[i+1];    
        }
        if(ans==7)break;
    }
    cout<<a[0]<<(b>>0&1?'+':'-');
    cout<<a[1]<<(b>>1&1?'+':'-');
    cout<<a[2]<<(b>>2&1?'+':'-');
    cout<<a[3]<<"=7"<<"\n";
    return 0;
}
