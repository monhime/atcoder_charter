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
static const int MAX=(int) 2e5;

int N,P[MAX+1],Q[MAX+1];
int k=1; //Q[]の最長部分列のサイズ
int aa,max_k=1;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> P[i];
    for(int i=1;i<=N;i++) Q[P[i]] = i;
    aa = Q[1];
    for(int i=2;i<=N;i++){
        if(aa<Q[i]) k++;
        else k=1;
        aa = Q[i];
        max_k = max(max_k,k);
    }
    cout << N - max_k <<"\n";
    return 0;
}

