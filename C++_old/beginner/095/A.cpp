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

int main(){
    string s;
    cin>>s;
    int cunt =0;
    for(int i=0;i<3;i++){
        if(s[i]=='o')
            cunt++;
    }

    cout<<700+100*cunt<<"\n";
    return 0;
}

