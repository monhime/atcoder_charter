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
static const int MAX=500;
int N;
int F[100][11],P[100][11];

int main(){ 
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<10;j++)
            cin>>F[i][j];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=10;j++)
            cin>>P[i][j];
    }
    int res=-(1<<30);
    for(int b=1;b<(1<<10);b++){
        int cc=0;
        for(int i=0;i<N;i++){
            int c=0;
            for(int j=0;j<10;j++){
                if((b>>j&1)&&F[i][j])c++;
            }
            cc+=P[i][c];
        }
        if(res<cc)res=cc;
    }
    cout<<res<<"\n";
    return 0;
}
