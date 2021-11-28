#include<iostream>
#include<cstdio>
#include<time.h>

using namespace std;

int main(){
    int i;             
    clock_t start,end;

    start=clock();
    for(i=0;i<1000000;i++)
        printf("1\n");
    end=clock();

    printf("%f秒",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
