import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,weight=map(int,input().split())
    WV=[tuple(map(int,input().split())) for i in range(n)]
    dp=[[0]*(weight+1) for _ in range(n+1)] #品物iまでについて，ナップサックの重さの総和がjのときの価値の総和
    for i in range(n):
        ni=i+1
        w,v=WV[ni-1]
        for j in range(weight+1):
            dp[ni][j]=max(dp[ni][j],dp[i][j])
            if j+w<=weight and (j==0 or dp[i][j]>0):
                dp[ni][j+w]=max(dp[ni][j+w],dp[i][j]+v)
    print(max(dp[n]))
            



if __name__=='__main__':
    main()