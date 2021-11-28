#include<iostream>
using namespace std;
typedef long long ll;

struct Stack{
    ll table[1000];
    ll top;
    void init(){
        top=0;
    }
    bool empty(){
        return top==0;
    }
    void push(ll x){
        table[top]=x;
        top++;
    }
    ll pop(){
        if(empty())return 0;
        top--;
        return table[top];
    }
};

ll calc(ll x,string op,ll y){
    if(op=="+")return x+y;
    if(op=="-")return x-y;
    if(op=="*")return x*y;
}


int main(){
    string str;
    ll numA,numB;
    Stack stack;
    stack.init();

    while(cin>>str){
        if(str=="+"||str=="-"||str=="*"){
            numA=stack.pop();
            numB=stack.pop();
            stack.push(calc(numB,str,numA));
        }else{
            numA=0;
            for(int i=0;i<(int)str.size();i++){
                numA*=10;
                numA+=str[i]-'0';
            }
            stack.push(numA);
        }
    }
    cout<<stack.pop()<<endl;
    return 0;
}

