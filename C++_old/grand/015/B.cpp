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
string s;
ll sum;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> s;
    
    for(int i=1;i<=s.size();i++){
        if(s[i-1] == 'U') sum += (i-1)*2 + s.size()-i;
        else sum += i-1 + (s.size()-i)*2;
    }
    cout << sum << "\n";
    return 0;
}

