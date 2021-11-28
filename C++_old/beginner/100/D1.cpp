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
long long N, M, a[100009][3], maxn = -(1LL << 60);

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) cin >> a[i][j];
    }
    for (int i = 0; i < 8; i++) {
        vector<long long> vec; //各場合のケーキの値の和の集合
        for (int j = 1; j <= N; j++) {
            long long S = 0; //各場合のケーキの値の和
            for (int k = 0; k < 3; k++) {
                if ((i / (1 << k)) % 2 == 0) S += a[j][k];//i>>k &1では？
                else S -= a[j][k];
            }
            vec.push_back(S);
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        long long ans = 0;
        for (int j = 0; j < M; j++) ans += vec[j]; //ケーキの値の和の大きい方からM個
        maxn = max(maxn, ans);
    }
    cout << maxn << endl;
    return 0;
}
