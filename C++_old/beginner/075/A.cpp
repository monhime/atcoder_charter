#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a!=b&&b==c)cout<<a<<"\n";
    else if(a!=b&&b!=c)cout<<b<<"\n";
    else if(a==b&&b!=c)cout<<c<<"\n";

    return 0;
}
