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
static const int MAX=100000;
int a[MAX];
int flag2,flag4,x;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x%4==0)flag4++;
        else if(x%2==0)flag2++;
    }
    if(flag2/2+flag4>=N/2)
        cout<<"Yes"<<"\n";
    else
        cout<<"No"<<"\n";
    return 0;
}

