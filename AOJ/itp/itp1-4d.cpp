#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int tmp,n;
    long long sum=0;

    cin>>n;
    
    int min_num=1000000;
    int  max_num=-1000000;

    for(int i=0;i<n;i++){
        cin>>tmp;
        min_num=min(min_num,tmp);
        max_num=max(max_num,tmp);
        sum+=tmp;
    }
    cout<<min_num<<" "<<max_num<<" "<<sum<<"\n";
    
    
    return 0;
}
