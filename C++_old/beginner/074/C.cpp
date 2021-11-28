#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
using namespace std;
map <int,int> mp_w,mp_s;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
int A,B,C,D,E,F,max_w,max_s;
double max_d=-1.0;
ll water,sugar;
int main(){
    cin>>A>>B>>C>>D>>E>>F;

    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            water=A*i+B*j;
            mp_w[water]++;
        }
    }

    for(int i=0;i<=2900;i++){
        for(int j=0;j<=2900;j++){
            sugar=C*i+D*j;
            mp_s[sugar]++;
        }
    }

    for(auto pw:mp_w){

        water=pw.first*100;
        if(water>F||water==0)continue;

        for(auto ps:mp_s){
            sugar=ps.first;
            if(water+sugar>F)continue;

            double d=(double)sugar/(water+sugar);
            double e=(double)sugar*100/water;
            if(e>E)continue;

            if(max_d<d){
                max_w=water;
                max_s=sugar;
                max_d=d;
            }
        }
    }

    cout<<max_w+max_s<<" "<<max_s<<"\n";

    return 0;
}
