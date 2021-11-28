#include<iostream>
#include<vector>

using namespace std;

int main(){
    int i,j,N;
    ios::sync_with_stdio(false); cin.tie(0);


    cin>>N;
    vector <string> data1(N),data2(N);

    for(i=0;i<N;i++){
        cin>>data1[i];
        data2[i]=data1[i];
    }
    //バブルソート
    for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
            if(data1[j][1]<data1[j-1][1])
                swap(data1[j],data1[j-1]);
        }
    }
    //選択ソート
    for(i=0;i<N;i++){
        int minj=i;
        for(j=i;j<N;j++)
            if(data2[j][1]<data2[minj][1])minj=j;
        swap(data2[i],data2[minj]);
    }
    for(i=0;i<N;i++)cout<<(i!=0?" ":"")<<data1[i];
    cout<<"\n"<<"Stable"<<"\n";
    for(i=0;i<N;i++)cout<<(i!=0?" ":"")<<data2[i];
    cout<<"\n"<<((data1==data2)?"Stable":"Not stable")<<"\n";
}
