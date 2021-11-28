import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, m = map(int,input().split())
    A = [int(input())for _ in range(m)]
    FLAG = [True] * (n + 2) # i段目が登れるか
    for a in A:
        FLAG[a] = False

    mod = 1000000007

    dp = [0] * (n + 2)
    dp[0] = 1
    for i in range(n):
        if FLAG[i + 1]:
            dp[i + 1] = (dp[i + 1] + dp[i]) % mod
        if FLAG[i + 2]:
            dp[i + 2] = (dp[i + 2] + dp[i]) % mod
    print(dp[n]%mod)


if __name__=='__main__':
    main()