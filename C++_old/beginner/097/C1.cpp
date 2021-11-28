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
using namespace std;

long long dp[1000001][30];

int main(){
    string str;
    cin >> str;
    long long k;
    cin >> k;
    int r = str.size();
    int l = 0;
    
    
    for (int i = r-1; i >= 0; i--){
        long long sum = 0;
        for (int j = 0; j < 26; j++){
            if (str[i] != 'a' + j) {
                dp[i][j] = dp[i+1][j];
            }
            sum += dp[i+1][j];
            if (sum > k) sum = k+1;
        }
        dp[i][str[i]-'a'] = sum+1;
    }
    
    while (k > 0) {
        int d = 0;
        for (int i = 0; i < 26; i++){
            if (k - dp[l][i] <= 0) break;
            k -= dp[l][i];
            d++;
        }
        for (int i = l; i < r; i++){
            if (str[i] - 'a' == d){
                l = i + 1;
                break;
            }
        }
        k--;
        cout << str[l-1];
    }
    cout << endl;
    return 0;
}
