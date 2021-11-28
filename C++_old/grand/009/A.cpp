#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<sstream>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX=(ll) 1e5;

int N;
ll A[MAX +2],B[MAX +2],cunt;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];
    for(int i=N-1;i>=0;i--){
        if(!((A[i]+cunt) % B[i])) continue;
        cunt += ((A[i]+cunt) / B[i] + 1ll) * B[i] - (A[i] + cunt);
    }
    cout << cunt <<"\n";
    return 0;
}

