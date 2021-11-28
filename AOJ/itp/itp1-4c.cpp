#include<iostream>
using  namespace std;

int main(){
    int a,b;
    char ch;
    while(cin>>a>>ch>>b){
        if(ch=='+')cout<<(a+b)<<"\n";
        else if(ch=='-')cout<<(a-b)<<"\n";
        else if(ch=='/')cout<<(a/b)<<"\n";
        else if(ch=='*')cout<<(a*b)<<"\n";
        else if(ch=='?')break;
    }
    return 0;
}
