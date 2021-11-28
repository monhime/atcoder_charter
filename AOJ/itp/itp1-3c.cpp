#include<iostream>
int main(){
    int a,b;
    while(std::cin>>a>>b&&!((a==b)&&a==0)){
        std::cout<<(a>b?b:a)<<" "<<(a>b?a:b)<<"\n";
    }
}
