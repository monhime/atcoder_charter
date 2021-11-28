#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>

using namespace std;
int main(){
    stack<int> S;
    int a,b,x;
    char s[101];

    while(scanf("%s",s)!=EOF){
        if(s[0]=='+'){
            a=S.top();
            S.pop();
            b=S.top();
            S.pop();
            S.push(a+b);
        }else if(s[0]=='-'){
            b=S.top();S.pop();
            a=S.top();S.pop();
            S.push(a-b);

        }else if(s[0]=='*'){
            a=S.top();S.pop();
            b=S.top();S.pop();
            S.push(a*b);
        }else
            S.push(atoi(s));
    }                              
    printf("%d\n",S.top());
    return 0;
}

