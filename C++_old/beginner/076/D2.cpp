#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX=100;
int g[MAX*400+2];

int n,t[MAX+2],v[MAX+2],ans;
int main(void){
	cin >> n;
	t[0]=0;
	for(int i=1;i<=n;i++){
		cin >>t[i];
		t[i]*= 2;//x->2*x座標にする
		t[i]+=t[i-1];//2*x座標と対応させる
	}
	for(int i=0;i<n;i++){
		cin >>v[i];
		v[i]*= 2;//y座標も2倍。傾きが1のまま。
	}
	for(int i=0;i<=t[n];i++){
		g[i]=min(i,t[n]-i);//t[0],t[n]の制限
		for(int j=0;j<n;++j){
			if(i<=t[j]){//i->t[j]->t[j+1]
				g[i]=min(g[i],v[j]+t[j]-i);
			}else if(t[j+1]<=i){//t[j]->t[j+1]->i
				g[i]=min(g[i],v[j]+i-t[j+1]);
			}else{//t[j]->j->t[j+1]
				g[i]=min(g[i],v[j]);
			}
		}
	}
	for(int i=0; i<t[n]; ++i){
		ans += g[i]+g[i+1];//台形の面積
	}
	printf("%.5lf\n",((double)(ans)/8));
	return 0;
}

