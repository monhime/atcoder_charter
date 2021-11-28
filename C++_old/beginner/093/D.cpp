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
int Q,A,B;
int main(){
    cin>>Q;
    while(Q--){
        cin>>A>>B;
        int cunt=0;
        int N=A*B;
        for(int k=1;k*k<=N-1;k++){
            bool flag=(k==A||k==B);
            if((2*k*k)<=N-1&&!flag)cunt+=2;
            else if((2*k*k)<=N-1&&flag)cunt++;
            else if(k*k<=N-1&&!flag)cunt++;
        }
        cout<<cunt<<"\n";
    }

    return 0;
}

