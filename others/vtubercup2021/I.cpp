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
string to_string(T s);
template <class S, class T>
string to_string(pair<S, T> p);
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char s[]) { return to_string(string(s)); }

template <class T>
string to_string(T v) {
    if (v.empty()) return "{}";
    string ret = "{";
    for (auto x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}

template <class S, class T>
string to_string(pair<S, T> p) {
    return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}


struct IO {
    string separator = " ";

    template <class T>
    inline void read(T& x) {
        char c;
        do {
            c = getchar_unlocked();
        } while (c != '-' && (c < '0' || '9' < c));
        bool minus = 0;
        if (c == '-') {
            minus = 1;
            c = getchar_unlocked();
        }
        x = 0;
        while ('0' <= c && c <= '9') {
            x *= 10;
            x += c - '0';
            c = getchar_unlocked();
        }
        if (minus) x = -x;
    }
    inline void read(string& x) {
        char c;
        do {
            c = getchar_unlocked();
        } while (c == ' ' || c == '\n');
        x.clear();
        do {
            x += c;
            c = getchar_unlocked();
        } while (c != ' ' && c != '\n' && c != EOF);
    }
    template <class T>
    inline void read(vector<T>& v) {
        for (auto& x : v) read(x);
    }
    template <class S, class T>
    inline void read(std::pair<S, T>& p) {
        read(p.first);
        read(p.second);
    }
    template <class Head, class... Tail>
    inline void read(Head& head, Tail&... tail) {
        read(head);
        read(tail...);
    }
    template <class T>
    inline void write(T x) {
        char buf[32];
        int p = 0;
        if (x < 0) {
            x = -x;
            putchar_unlocked('-');
        }
        if (x == 0) putchar_unlocked('0');
        while (x > 0) {
            buf[p++] = (x % 10) + '0';
            x /= 10;
        }
        while (p) {
            putchar_unlocked(buf[--p]);
        }
    }
    inline void write(string x) {
        for (char c : x) putchar_unlocked(c);
        }
    inline void write(const char s[]) {
        for (int i = 0; s[i] != 0; ++i) putchar_unlocked(s[i]);
    }
    template <class T>
    inline void write(vector<T> v) {
        if (v.empty()) return;
        for (auto itr = v.begin(); itr + 1 != v.end(); ++itr) {
            write(*itr);
            write(separator);
        }
        write(v.back());
    }
    template <class Head, class... Tail>
    inline void write(Head head, Tail... tail) {
        write(head);
        write(separator);
        write(tail...);
    }
    template <class Head, class... Tail>
    inline void writeln(Head head, Tail... tail) {
        write(head, tail...);
        write("\n");
    }
    void set_separator(string s) { separator = s; }
} io;

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

int main(){

    double a, b, h, m;
    io.read(a, b, h, m);

    double theta_h, theta_m;
    theta_h = 30 * h + m/2;
    theta_m = 6 * m;

    double ans = sqrt(a * a + b * b - 2 * a * b * cos(abs(theta_h - theta_m)*M_PI/180));
    printf("%.16f\n", ans);

    return 0;
}
