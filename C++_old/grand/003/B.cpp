#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<sstream>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX=(int) 1e5;
int N,rest;
ll A[MAX+2],sum;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    
    for(int i=0;i<N;i++){
        if(A[i]%2){
            if(i<N-1 && A[i+1]>0) {
                sum += (A[i] +1)/2;
                A[i+1]--;
            }else sum += A[i]/2;
        }else sum += A[i]/2;
    }
    cout << sum <<"\n";
    return 0;
}

