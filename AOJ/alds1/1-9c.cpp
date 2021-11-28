#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
static const int MAX=2000000000;
static const int INFITY=2000000001;

int H,A[MAX+1];
void maxHeapify(int i){
    int l,r,largest;
    l=2*i;
    r=2*i+1;
    if(l<=H&&A[l]>A[H])largest=l;
    else largest=i;
    if(r<=H&&A[r]>A[largest])largest=r;
    if(largest!=i){
        swap(A[largest],A[i]);
        maxHeapify(largest);
    }
}
int extract(){
    int maxv;
    if(H<1)return -INFITY;
    maxv=A[1];
    A[1]=A[H--];
    maxHeapify(1);
    return maxv;
}
void increaseKey(int i,int key){
    if(key<A[i])return;
    A[i]=key;
    while(i>1&&A[i/2]<A[i]){
        swap(A[i],A[i/2]);
        i/=2;
    }
}
void insert(int key){
    H++;
    A[H]=-INFITY;
    increaseKey(H,key);
}  
int main(){
    int key;
    char com[10];
    while(1){
        cin>>com;
        if(com[0]=='e'&&com[1]=='n')break;
        if(com[0]=='i'){
            cin>>key;
            insert(key);
        }else
            cout<<extract()<<"\n";
    }
    return 0;
}





