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
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
#define debug(x) cerr << #x << ": " << x << "\n";
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=(int) 2e5;
static const int MOD=(int) 1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,ans;
ll A[MAX+2];
double sum,sum1;
int status0=0,status1=0;
bool flag=false;

ll f(int b){
    ll sum=0ll;
    for(int i=1;i<=N;i++){
        sum+=abs(A[i]-b);
    }
    return sum;
}


/*整数~整数
 l:範囲最小値,r:範囲最大値
 x<rでf=false,x>=rでtrue
 */
ll binary_search2(ll l,ll r){
    while(r-l>1ll){ //r=l+1になるまで
        ll m=(l+r)/2ll; //平均値かその左の整数
        if(f(m))r=m; //カッコ内の条件式は任意
        else l=m; //解x>m
    }
    return r;
}



int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        A[i]-=i;
        status1 = A[i]>0 ? 1:(A[i]<0 ? -1:0);
        if(status1 * status0<0) flag=true;
        status0=status1;
        sum+=(double)A[i];
    }
    if(!flag && status1==1){
        sum1=sum/N;
        if(sum1-(int)sum1<0.5) ans = (int)sum1;
        else ans=(int)sum1+1;
        cout << abs(sum-ans*N) <<"\n";
    }else if(!flag && status1==-1){
        sum1=sum/(double)N;
        //0~sum1-1でbinary
        int b=binary_search2(sum1-1,0);
        cout<<f(b)<<"\n";;
    }
    
    return 0;
}
