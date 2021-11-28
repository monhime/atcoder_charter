#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
//#include <bits/stdc++.h>
using namespace std;
int A,B,K;
int main(){
    cin>>A>>B>>K;
    if(A+K-1>=B-K+1){
        for(int i=A;i<=B;i++)
            cout<<i<<"\n";
    }else{
        for(int i=A;i<A+K;i++)
            cout<<i<<"\n";
        for(int i=B-K+1;i<=B;i++)
            cout<<i<<"\n";
    }    
    return 0;
}

