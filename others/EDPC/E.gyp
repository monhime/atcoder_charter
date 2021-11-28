import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,weight=map(int,input().split())
    WV=[tuple(map(int,input().split())) for i in range(n)]
    dp=[[10**10]*(10**5+1) for _ in range(n+1)] #i番目までの品物について，価値の総和がjのときのナップザックの重さ
    dp[0][0]=0
    for i in range(n):
        ni=i+1
        w,v=WV[ni-1]
        for j in range(10**5+1):
            if dp[i][j]+w<=weight and (j==0 or dp[i][j]!=10**10):
                dp[ni][j+v]=min(dp[ni][j+v],dp[i][j]+w)
            dp[ni][j]=min(dp[i][j],dp[ni][j])
    for i in range(10**5,-1,-1):
        if dp[-1][i]!=10**10:
            print(i)
            break

if __name__=='__main__':
    main()