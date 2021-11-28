import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h,w=map(int,input().split())
    A=[input() for _ in range(h)]
    dp=[[0]*w for _ in range(h)] #(i,j)までの経路の総数
    dp[0][0]=1
    mod=10**9+7
    for i in range(h):
        for j in range(w):
            if A[i][j]=="#":continue
            if i>=1 and j>=1:    
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%mod
            elif j==0:
                dp[i][j]+=dp[i-1][j]%mod
            else:
                dp[i][j]+=dp[i][j-1]%mod
    print(dp[-1][-1]%mod)

if __name__=='__main__':
    main()