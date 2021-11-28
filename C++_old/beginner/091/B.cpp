#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int N,M;
int main(){
    cin>>N;
    char s[N][11];
    for(int i=0;i<N;i++)
        cin>>s[i];
    cin>>M;
    char t[M][11];
    for(int j=0;j<M;j++)
        cin>>t[j];
    
    int cunt[N];
    for(int i=0;i<N;i++){
        cunt[i]=1;
        for(int j=i+1;j<N;j++){
            if(strcmp(s[i],s[j])==0)
                cunt[i]++;
        }
        for(int j=0;j<M;j++){
            if(strcmp(s[i],t[j])==0)
                cunt[i]--;
        }
    }
    
    int max_num=-100;
    for(int i=0;i<N;i++){
        if(cunt[i]>max_num){
            max_num=cunt[i];
        }    
        
    }
    
    cout<<(max_num>=0?max_num:0)<<"\n";
    
    return 0;
    

}
