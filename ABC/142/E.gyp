import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    dp=[10**10]*(1<<n)
    dp[0]=0
    for i in range(m):
        a,b=map(int,input().split())
        C=list(map(int,input().split()))
        d=0
        for c in C:
            d|=1<<(c-1)
        for j in range(1<<n):
            dp[j|d]=min(dp[j|d],dp[j]+a)
    if dp[-1]==10**10:
        print(-1)
    else:
        print(dp[-1])
        
if __name__=='__main__':
    main()