#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

//数列a(a[0],a[1],…,a[n-1])についての区間和と点更新を扱う
//区間和,点更新,二分探索はO(log{n})で動作する
//https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
class BIT {
public:
    ll n;
    vector<ll> a;
    BIT(ll n):n(n),a(n+1,0){}
    void add(ll i,ll x){ //a[i]+=x
        i++;
        if(i == 0) return;
        for(ll k = i;k <= n;k += (k & -k)){
            a[k] += x;
        }
    }
    //a[i]+a[i+1]+…+a[j]を求める
    ll sum(ll i,ll j){
        return sum_sub(j) - sum_sub(i - 1);
    }
    //a[0]+a[1]+…+a[i]を求める
    ll sum_sub(ll i){
        i++;
        ll s = 0;
        if(i == 0) return s;
        for(ll k = i;k > 0;k -= (k & -k)){
            s += a[k];
        }
        return s;
    }
    //a[0]+a[1]+…+a[i]>=xとなる最小のiを求める(任意のkでa[k]>=0が必要)
    ll lower_bound(ll x){
        if(x <= 0){
            //xが0以下の場合は該当するものなし→0を返す
            return 0;
        }else{
            ll i = 0;ll r = 1;
            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(r < n) r = (r << 1);
            //区間の長さは調べるごとに半分になる
            for(int len = r;len > 0;len = (len >> 1)) {
                //その区間を採用する場合
                if(i + len < n && a[i + len] < x){
                    x -= a[i + len];
                    i += len;
                }
            }
            return i;
        }
    }
};

class BIT {
public:
    ll n;
    vector<ll> a;
    BIT(ll n):n(n),a(n+1,0){}
    void add(ll i,ll x){ //a[i]+=x
        i++;
        if(i == 0) return;
        for(ll k = i;k <= n;k += (k & -k)){
            a[k] += x;
        }
    }
    //a[i]+a[i+1]+…+a[j]を求める
    ll sum(ll i,ll j){
        return sum_sub(j) - sum_sub(i - 1);
    }
    //a[0]+a[1]+…+a[i]を求める
    ll sum_sub(ll i){
        i++;
        ll s = 0;
        if(i == 0) return s;
        for(ll k = i;k > 0;k -= (k & -k)){
            s += a[k];
        }
        return s;
    }
    //a[0]+a[1]+…+a[i]>=xとなる最小のiを求める(任意のkでa[k]>=0が必要)
    ll lower_bound(ll x){
        if(x <= 0){
            //xが0以下の場合は該当するものなし→0を返す
            return 0;
        }else{
            ll i = 0;ll r = 1;
            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(r < n) r = (r << 1);
            //区間の長さは調べるごとに半分になる
            for(int len = r;len > 0;len = (len >> 1)) {
                //その区間を採用する場合
                if(i + len < n && a[i + len] < x){
                    x -= a[i + len];
                    i += len;
                }
            }
            return i;
        }
    }
};

int main(){
    ios::sync_with_stdio(false); //対話的出力のときはコメントアウト
    std::cin.tie(nullptr);

    

    cin >> ;
    
    cout << << "\n";

    return 0;
}
