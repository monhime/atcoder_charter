#include<iostream>
using namespace std;
typedef long long ll;

string s;
int N;
ll m,a,r,c,h=0;
ll D[5];
int P[10]={0,0,0,0,0,0,1,1,1,2};
int Q[10]={1,1,1,2,2,3,2,2,3,3};
int R[10]={2,3,4,3,4,4,3,4,4,4};
int main(){
    cin>>N;
    while(N--){
        cin>>s;
        if(s[0]=='M')m++;
        if(s[0]=='A')a++;
        if(s[0]=='R')r++;
        if(s[0]=='C')c++;
        if(s[0]=='H')h++;
    }
    ll x=0;
    D[0]=m,D[1]=a,D[2]=r,D[3]=c,D[4]=h;
    for(int i=0;i<10;i++){
        x+=D[P[i]]*D[Q[i]]*D[R[i]];
    }
    cout<<x<<"\n";
    return 0;


}
