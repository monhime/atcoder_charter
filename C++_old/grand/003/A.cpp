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
map <char,int> mp;

string s;

bool XOR(int a,int b){
    return !a != !b;
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> s;
   
    for(int i=0;i<s.size();i++) mp[s[i]]++;
    
    if(XOR(mp['N'],mp['S']) || XOR(mp['W'],mp['E'])) cout << "No" <<"\n";
    else cout << "Yes" <<"\n";
    return 0;
}

