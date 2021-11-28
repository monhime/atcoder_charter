#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
//#include <bits/stdc++.h>
using namespace std;
int A,B,C;

void swap(int *nx, int *ny)
{
    int temp = *nx;
    *nx = *ny;
    *ny = temp;
}

/*--- *n1≦*n2≦*n3となるように並べ替える ---*/
void sort3(int *n1, int *n2, int *n3)
{
    if (*n1 > *n2) swap(n1, n2);
    if (*n2 > *n3) swap(n2, n3);
    if (*n1 > *n2) swap(n1, n2);
}
int cunt;
int main(){

    cin>>A>>B>>C;
    sort3(&C,&B,&A);
    while(1){
        if(A>=B+2){
            cunt++;    
            B+=2;
        }else
            break;
   }     
   while(1){
        if(A>=C+2){
            C+=2;
            cunt++;
        }else
            break;
    }
    sort3(&C,&B,&A);
    if(A==B&&B==C)
        cout<<cunt<<"\n";
    else if(A==B&&B>C)
        cout<<cunt+2<<"\n";
    else
        cout<<cunt+1<<"\n";
    return 0;    

}

