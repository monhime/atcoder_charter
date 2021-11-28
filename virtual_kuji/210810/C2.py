import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, m = map(int,input().split())
    A = [int(input())for _ in range(m)]

    mod = 1000000007

    dp = [0] * (n + 2)
    dp[0] = 1
    if m != 0:
        next_a = A[0]
        next_a_i = 0
    for i in range(n):
        if m == 0:
            dp[i + 1] = (dp[i + 1] + dp[i])%mod
            dp[i + 2] = (dp[i + 2] + dp[i])%mod   
        elif next_a == i + 2:
            dp[i + 1] = (dp[i + 1] + dp[i]) % mod
        elif next_a == i + 1:
            if next_a_i + 1 < m and A[next_a_i + 1] == next_a + 1:
                print(0)
                exit()
            dp[i + 2] = (dp[i + 2] + dp[i]) % mod
            if next_a_i + 1 < m:
                next_a = A[next_a_i + 1]
            else:
                next_a = n + 1
        else:
            dp[i + 1] = (dp[i + 1] + dp[i])%mod
            dp[i + 2] = (dp[i + 2] + dp[i])%mod   
        #print(dp)
    print(dp[n]%mod)


if __name__=='__main__':
    main()