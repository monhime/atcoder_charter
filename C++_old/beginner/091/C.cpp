#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int N;

void sort_array(int **x){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(x[i][0]>x[j][0])
                swap(x[i],x[j]);
        }
    }
}

int main(){
    cin>>N;
    int a[N][2],b[N][2];
    for(int i=0;i<N;i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<N;i++){
        cin>>b[i][0]>>b[i][1];
    }
    int cunt=0;
    int  **cut;
    cut=(int **)calloc(2,sizeof(int *));
    for(int i=0;i<2;i++)
        cut[i]=(int *)calloc(N*N,sizeof(int*));    

    for(int i=0;i<N;i++){
        if(cut[0][i]||cut[1][i])continue;
        for(int j=0;j<N;j++){
            if(cut[0][j]||cut[1][j])continue;
            if(a[i][0]<b[j][0]&&a[i][1]<b[j][1]){            
            
                cunt++;
                cut[0][i]=1;
                cut[0][j]=1;
                cut[1][i]=1;
                cut[1][j]=1;
            }


        }
    }
    cout<<cunt<<"\n";

    
    return 0;


    
}
