import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=list(map(int,input().split()))
    cum_A=[0]*(n+1) #Aの[0,i)の和
    for i in range(1,n+1):
        cum_A[i]=cum_A[i-1]+A[i-1]
    dp=[[0]*(n+1) for _ in range(n+1)]  #[i,j)をまとめるために必要なコストの最小値
    for length in range(2,n+1):
        for i in range(n-length+1):
            j=i+length #右側
            res=10**20
            for k in range(i+1,j):#区間[i,k)と[k,j)に分ける
                res=min(res,dp[i][k]+dp[k][j])
            dp[i][j]=res+cum_A[j]-cum_A[i]
    print(dp[0][n])


if __name__=='__main__':
    main()