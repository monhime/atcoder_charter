#include <bits/stdc++.h>
using namespace std;

char A[5][5]; // 盤面の情報
int b[5][5], c[5][5]; // 得点の情報

// 盤面を埋め終わったとき、直大の得点を返す
int calc() {
    int score = 0;
    // b[2][3]についての直大の得点
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == A[i+1][j]) score += b[i][j];
        }
    }
    // c[3][2]についての直大の得点
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (A[i][j] == A[i][j+1]) score += c[i][j];
        }
    }
    return score;
}

// 盤面を全通りに埋めるDFS
int dfs(int turn) {
    // 全部埋め終わったら直大君の得点を計算する
    if (turn == 9) return calc();
    
    if (turn % 2 == 0) { // 直大の手番
        int Max = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A[i][j] != '*') continue;
                A[i][j] = 'o'; // 盤面に'o'を打つ
                // 今の盤面の状態で、次に'x'が打たれるわけだが、その時のMinがdfs()で返ってくる
                Max = max(Max, dfs(turn + 1));
                A[i][j] = '*'; // 盤面を元に戻す
            }
        }
        return Max;
    } else { // 直子の手番
        int Min = 1e8;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (A[i][j] != '*') continue;
                A[i][j] = 'x'; // 盤面に'x'を打つ
                // 今の盤面の状態で、次に'o'が打たれるわけだが、その時のMaxがdfs()で返ってくる
                Min = min(Min, dfs(turn + 1));
                A[i][j] = '*'; // 盤面を元に戻す
            }
        }
        return Min;
    }
}

int main() {
    // 入力
    int sum = 0; // 全体の合計
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
            sum += b[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> c[i][j];
            sum += c[i][j];
        }
    }
    
    // 盤面を全て'*'で初期化
    fill(A[0], A[5], '*');
    
    int chokudai = dfs(0); // 直大の得点が返ってくる
    cout << chokudai << endl;
    cout << sum - chokudai << endl; // 直子の得点は(合計 - 直大の得点)となる
    
    return 0;
}
