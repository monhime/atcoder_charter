import sys
def input(): return sys.stdin.readline().rstrip()
    
def main():
    n,m=map(int,input().split())
    A=[int(input())for _ in range(m)]
    flag=[True]*(n+2)
    for a in A:
        flag[a]=False
    mod=10**9+7
    dp=[0]*(n+1)
    dp[0]=1
    for i in range(n):
        if flag[i+1]:
            dp[i+1]+=dp[i]%mod
        if flag[i+2] and i<n-1:
            dp[i+2]+=dp[i]%mod
    print(dp[n]%mod)

if __name__=='__main__':
    main()