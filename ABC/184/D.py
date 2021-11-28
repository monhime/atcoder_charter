import sys
def input(): return sys.stdin.readline().rstrip()
 # dp[i][j][k] = 金がi, 銀がj, 銅がk枚になる確率
dp = [[[0] * 101 for i in range(101)] for j in range(101)]
def f(a, b, c):
    if dp[a][b][c]: #既にもとめていたら
        return dp[a][b][c]
    if a == 100 or b == 100 or c == 100: #終了点
        return 0
    ans = 0
    ans += (f(a + 1, b, c) + 1)*a/(a + b + c)
    ans += (f(a, b + 1, c) + 1)*b/(a + b + c) 
    ans += (f(a, b, c + 1) + 1)*c/(a + b + c)
    dp[a][b][c] = ans
    return ans 
    
def main():
    a, b, c  = map(int,input().split())
    print(f(a, b, c))

if __name__=='__main__':
    main()