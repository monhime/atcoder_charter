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
#include<ctime>
#include<time.h>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getDigit(ll n){
    return to_string(n).length();
}

int main(){
    ll N;
    cin>>N;

    int min_digit=getDigit(N);

    for(ll i=1ll;i*i<=N;i++){
        if(N%i)continue;
        ll j=N/i;
        int cur=getDigit(j);

        if(min_digit>cur)min_digit=cur;
    }
    cout<<min_digit<<"\n";
    return 0;    
}


