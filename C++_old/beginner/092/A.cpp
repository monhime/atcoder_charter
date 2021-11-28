#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int ans;
    ans=min(A,B)+min(C,D);
    cout<<ans<<"\n";
    return 0;
}

