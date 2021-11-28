#include <cmath>
#include <cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int s[105];
    int p=2;
    int i;
    s[1]=3;
    s[2]=4;

    s[p]+=s[p--];
    for(i=0;i<3;i++){
        cout<<"s[0]:"<<s[0]<<"\n";
    }    
    return 0;
}
