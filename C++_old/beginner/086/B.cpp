#include<iostream>
#include<math.h>
using namespace std;
int a,b,c;
float d;
int main(){
    cin>>a>>b;
    if(b<10)c=10*a+b;
    else if(b<100) c=100*a+b;
    else c=1000*a+b;

    d=sqrt(c);
    cout<<(c==(int)d*d?"Yes":"No")<<"\n";
    return 0;


}
