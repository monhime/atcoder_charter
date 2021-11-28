#include<iostream>
#include<cstdio>
using namespace std;
static const int MAX=100000;

int parent(int i){return i/2;}
int left(int i){return i*2;}
int right(int i){return i*2+1;}

int main(){
    int H,A[MAX+1];
    cin>>H;

    for(int i=1;i<=H;i++)cin>>A[i];
    for(int i=1;i<=H;i++){
        cout<<"node "<<i<<": key = "<<A[i]<<", ";
        if(parent(i)>=1)
            cout<<"parent key = "<<A[parent(i)]<<", ";
        if(left(i)<=H)
            printf("left key = %d, ",A[left(i)]);
        if(right(i)<=H)
            printf("right key = %d, ",A[right(i)]);
        putchar('\n');
    }
    return 0;
        
}

