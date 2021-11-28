#include<cstdio>
#include<cmath>
#include<iostream>

int main(){
    int X,K;
    int Y;

    scanf("%d %d",&X,&K);

    Y=X-X% (int)std::pow(10,K)+std::pow(10,K);

    printf("%d",Y);

    return 0;


}
