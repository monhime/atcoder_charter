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

string s;
int cunt,sum;
bool flag=true;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> s;
    for(int i=1;i<s.size();i++){
        if(s[i]!='9') flag = false;
    }
    if(flag) cout << 9*(s.size()-1)+ (s[0]-'0')<<"\n";
    else{
        cout << 9*(s.size()-1) + (s[0]-'0')-1 <<"\n";
    }
    
}
