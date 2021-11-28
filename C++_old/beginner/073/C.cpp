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
int ans,cunt,A[MAX];
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>A[i];
    sort(A,A+N);
    int ptr=0;
    while(ptr<N){
        cunt=0;
        int cc=A[ptr];
        while(ptr<N&&A[ptr]==cc){
            cunt++;
            ptr++;
        }
        ans+=cunt%2;
    }
    cout<<ans<<"\n";
    return 0;
}
