import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=list(map(int,input().split()))
    #区間[i,j)のときのX-Yの最大値
    dp=[[0]*(n+1) for _ in range(n+1)] 
    for length in range(1,n+1): #長さ l=j-i
        for i in range(n-length+1): #区間開始0~n-l
            j=i+length #区間右
            if (n-length)%2==0:#先手:それまでに取った数が偶数 
                dp[i][j]=max(dp[i+1][j]+A[i],dp[i][j-1]+A[j-1])
            else: #後手:取った数が奇数
                dp[i][j]=min(dp[i+1][j]-A[i],dp[i][j-1]-A[j-1])
    print(dp[0][n])

if __name__=='__main__':
    main()