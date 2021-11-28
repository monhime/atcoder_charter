#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
int N,D,X;
int main(){
    cin>>N>>D>>X;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int x[N];
    for(int i=0;i<N;i++){
        x[i]=0;
        int day1=0;
        int day2=0;
        while(day2<=D){
            day2=day1*A[i]+1;
            day1++;
            x[i]++;
        }
        x[i]--;
    }
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=x[i];
    }
    cout<<X+sum<<"\n";
    return 0;


}

