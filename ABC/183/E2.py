import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h, w = map(int,input().split())
    S = [input() for i in range(h)]
    dp = [[0] * w for _ in range(2)]
    X = [[0] * w for _ in range(2)]
    Y = [[0] * w for _ in range(2)]
    Z = [[0] * w for _ in range(2)] 
    mod = 10**9 + 7
    dp[0][0] = 1
    for i in range(h):
        ii = i % 2
        for j in range(w):
            if S[i][j] == '#':
                continue
            if i == 0 and j == 0:
                continue
            if j > 0:
                X[ii][j] = (X[ii][j - 1] + dp[ii][j - 1]) % mod
            else:
                X[ii][j] = 0
            if i > 0:
                Y[ii][j] = (Y[ii ^ 1][j] + dp[ii ^ 1][j]) % mod
            else:
                Y[ii][j] = 0
            if i > 0 and j > 0:
                Z[ii][j] = (Z[ii ^ 1][j - 1] + dp[ii ^ 1][j - 1]) % mod
            else:
                Z[ii][j] = 0
            dp[ii][j] = (X[ii][j] + Y[ii][j] + Z[ii][j])%mod
    print(dp)
    print(dp[(h - 1) % 2][w - 1])


if __name__=='__main__':
    main()