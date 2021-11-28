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
int main(){
    int N,M,X,cunt;
    cin>>N>>M>>X;
    int A[M];
    for(int i=0;i<M;i++)cin>>A[i];
    cunt=0;
    for(int i=0;i<M;i++){
        if(A[i]<X)cunt++;
        else break;
    }
    cout<<(cunt*2<M?cunt:M-cunt)<<"\n";


    return 0;
}
