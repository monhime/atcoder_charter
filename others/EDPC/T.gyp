import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    mod=10**9+7
    #i(1-)番目の数まで決めた時，それより大きな数がj個ある場合の数
    dp=[[0]*(n+1) for _ in range(n+1)] 
    for i in range(n):
        dp[1][i]=1
    cum=[0]*(n+1)
    for i in range(2,n+1):
        cum[0]=dp[i-1][0]
        for j in range(1,n-i+2):
            cum[j]=(cum[j-1]+dp[i-1][j])%mod
        if s[i-2]=="<":
            for j in range(n-i+1):
                dp[i][j]=(cum[n-i+1]-cum[j])%mod
        else:
            for j in range(n-i+1):
                dp[i][j]=(cum[j])%mod
    print(dp[n][0])
if __name__=='__main__':
    main()