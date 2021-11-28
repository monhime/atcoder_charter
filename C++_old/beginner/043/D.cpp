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
int main(){
    string s;cin>>s;
    for(int i=0;s[i+1];i++){
        if(s[i]==s[i+1]||s[i]==s[i+2]||s[i+1]==s[i+2]){
            cout<<i+1<<" "<<(s[i+2]?i+3:i+2)<<"\n";
            return 0;
        }
    }
    cout<<-1<<" "<<-1<<"\n";
    return 0;
}
