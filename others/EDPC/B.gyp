import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    H=list(map(int,input().split()))
    dp=[-1]*n #足湯iまでに着くまでに支払うコストの総和の最小値
    dp[0]=0
    for i in range(n):
        for j in range(1,k+1):
            ni=i+j
            if ni>=n:continue
            if dp[ni]==-1:
                dp[ni]=dp[i]+abs(H[ni]-H[i])
            else:
                dp[ni]=min(dp[ni],dp[i]+abs(H[ni]-H[i]))
    print(dp[n-1])
if __name__=='__main__':
    main()