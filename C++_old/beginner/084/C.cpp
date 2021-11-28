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
typedef pair<int, int> P;
static const int MAX=500;
int N,t[MAX+1],s[MAX+1],c[MAX+1],f[MAX+1];
int main(){
    cin>>N;
    for(int i=1;i<N;i++){
        cin>>c[i]>>s[i]>>f[i];
    }

    for(int i=1;i<N;i++){
        t[i]=s[i];
        for(int j=i;j<N-1;j++){   
            t[i]+=c[j];
            while(t[i]%f[j+1]||t[i]<s[j+1])
                t[i]++;
        }
        t[i]+=c[N-1];
    }
    t[N]=0;

    for(int i=1;i<=N;i++){
        cout<<t[i]<<"\n";
    }

    return 0;
}

