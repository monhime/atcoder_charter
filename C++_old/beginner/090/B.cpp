#include<iostream>
using namespace std;
int A,B,cunt,num;
int main(){
    cin>>A>>B;
    for(num=A;num<=B;num++){
        int reverse = 0;
        int remaind;
        int tmp;

        tmp = num;
        while(tmp!=0)
        {
            remaind = tmp % 10;
            reverse = reverse * 10 + remaind;
            tmp /= 10;
        }
        /* 反転した数値と元の数値を比較 */
        if( reverse == num )
            cunt++;
    }           

   
    cout<<cunt;
    return 0;
}


