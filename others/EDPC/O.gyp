import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import product
def main():
    n=int(input())
    A=[[int(_) for _ in input().split()] for i in range(n)]
    dp=[0]*(1<<n)
    dp[0]=1
    mod=10**9+7
    for s in range(1<<n):
        i=bin(s).count("1")
        for j in range(n):
            if (s>>j)&1 and A[i-1][j]==1:
                dp[s]=(dp[s]+dp[s^(1<<j)])%mod
    print(dp[(1<<n)-1])

if __name__=='__main__':
    main()