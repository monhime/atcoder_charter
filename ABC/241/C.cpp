#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  // 横
  for (int i = 0; i < n; i++) {
    int cunt_sharp = 0;
    for (int j = 0; j < 6; j++) {
      if (S[i][j] == '#') {
        cunt_sharp++;
      }
    }
    if (cunt_sharp >= 4) {
      cout << "Yes\n";
      return 0;
    }
    for (int j = 1; j < n - 5; j++) {
      if (S[i][j + 5] == '#') {
        cunt_sharp++;
      }
      if (S[i][j - 1] == '#') {
        cunt_sharp--;
      }
      if (cunt_sharp >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  //縦
  for (int j = 0; j < n; j++) {
    int cunt_sharp = 0;
    for (int i = 0; i < 6; i++) {
      if (S[i][j] == '#') {
        cunt_sharp++;
      }
    }
    if (cunt_sharp >= 4) {
      cout << "Yes\n";
      return 0;
    }
    for (int i = 1; i < n - 5; i++) {
      if (S[i + 5][j] == '#') {
        cunt_sharp++;
      }
      if (S[i - 1][j] == '#') {
        cunt_sharp--;
      }
      if (cunt_sharp >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  }

  // 右下斜め
  for (int i = 0; i < n - 5; i++) {
    for (int j = 0; j < n - 5; j++) {
      // 開始地点(i, j)
      int cunt_sharp = 0;
      for (int k = 0; k < 6; k++) {
        if (S[i + k][j + k] == '#') {
          cunt_sharp++;
        }
      }
      if (cunt_sharp >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  // 左下斜め
  for (int i = 0; i < n - 5; i++) {
    for (int j = 5; j < n; j++) {
      // 開始地点(i, j)
      int cunt_sharp = 0;
      for (int k = 0; k < 6; k++) {
        if (S[i + k][j - k] == '#') {
          cunt_sharp++;
        }
      }
      if (cunt_sharp >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}
