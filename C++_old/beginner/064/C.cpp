#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
//#include <bits/stdc++.h>
using namespace std;
int cunt,cunt0,color[9],a;

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>a;
        if(a<3200)color[a/400]++;//color[0]~color[7]
        else color[8]++;
    }
    for(int i=0;i<8;i++){
        if(color[i])cunt++;
    }

    int min_cunt=max(cunt,1);

    int max_cunt=cunt+color[8];

    cout<<min_cunt<<" "<<max_cunt<<"\n";

    return 0;
}

