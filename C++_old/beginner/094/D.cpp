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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
   
    int max=-1;
    for(int i=0;i<n;i++){
        if(a[i]>max)max=a[i];
    }
    double median;
        median=(double)max/2;
    int min=1000000000;
    int min_num;
    for(int i=0;i<n;i++){
        double d=abs(a[i]-median);
        if(a[i]==max)continue;
        if(d<min){
            min=d;
            min_num=i;
        }    
    }
    cout<<max<<" "<<a[min_num]<<"\n";
    return 0;
}
