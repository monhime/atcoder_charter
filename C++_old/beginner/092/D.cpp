#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
int main(){
    int A,B;
    cin>>A>>B;
    if(((A+B-2)>50){

            }else{

            if(A==1&&B==1){
            cout<<1<<" "<<2<<"\n";
            cout<<".#";
            }else if(A==1){
            cout<<2<<" "<<2*B<<"\n";
            for(int i=0;i<B;i++)cout<<"..";
            cout<<"\n";
            for(int i=0;i<B;i++) cout<<".#";
            }
            else if(B==1){
            cout<<2<<" "<<2*B<<"\n";
            for(int i=0;i<A;i++)cout<<"##";
            cout<<"\n";
            for(int i=0;i<A;i++) cout<<"#.";
            }


            else{
                cout<<2<<" "<<2*(A+B-2)<<"\n";
                for(int i=0;i<A+B-2;i++){
                    cout<<".#";
                }
                cout<<"\n";
                for(int i=0;i<A-1;i++){
                    cout<<"##";
                }
                for(int i=0;i<B-1;i++){
                    cout<<"..";

                }
            }
            }
    cout<<"\n";
    return 0;
}

