#include<iostream>
#include<cstdlib>
using namespace std;
int N,d,t[2],x[2],y[2];
bool flag=1; 
int main(){
    cin>>N;
    while(N--){
        cin>>t[1]>>x[1]>>y[1];
        d=abs(x[1]-x[0])+abs(y[1]-y[0]);
        flag*=((t[1]-t[0]>=d&(t[1]-t[0]-d)%2==0)?1:0);
        swap(x[0],x[1]);
        swap(y[0],y[1]);                      
        swap(t[0],t[1]);
        
    }
    cout<<(flag?"Yes":"No")<<"\n";
    return 0;
    
}
