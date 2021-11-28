import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    dp=[[0]*(k+1) for _ in range(n+1)]
    dp[0][0]=1
    cum=[0]*(k+2)
    mod=10**9+7
    for i in  range(1,n+1):
        cum[0]=0 #dp[i-1]のj未満の和
        for j in range(k+1):
            cum[j+1]=cum[j]+dp[i-1][j]
        for j in range(k+1):
            dp[i][j]=(cum[j+1]-cum[max(0,j-A[i-1])])%mod
    print(dp[n][k])
if __name__=='__main__':
    main()