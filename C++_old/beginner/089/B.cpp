#include <iostream>
using namespace std;
int main(){
    int N;
    char s;
    cin>>N;
    while(N--){
        cin>>s;
        if(s=='Y'){
            cout<<"Four"<<"\n";
            return 0;
        }
    }
    cout<<"Three"<<"\n";
}
