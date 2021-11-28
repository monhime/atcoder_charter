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
ll A,B,C,K;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> A >> B >> C >> K;
    if(K&1){
        if(B-A>(ll)1e18) cout << "Unfair" <<"\n";
        else cout << B-A <<"\n";
    }
    else{
        if(A-B>(ll)1e18) cout << "Unfair" << "\n";
        else cout << A-B <<"\n";
    }
    return 0;
}

