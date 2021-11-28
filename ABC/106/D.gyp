import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m,q=map(int,input().split())
    LR=[tuple(map(int,input().split())) for i in range(m)]
    PQ=[tuple(map(int,input().split())) for i in range(q)]
    dp=[[0]*(n+1) for _ in range(n+1)] #i(1-)以上j(1-)以下の間に完全に含まれる列車の本数
    for l,r in LR:
        dp[l][r]+=1
    for i in range(n+1):
        for j in range(n):
            dp[i][j+1]+=dp[i][j]
    for i in range(n-1,0,-1):
        for j in range(n+1):
            dp[i][j]+=dp[i+1][j]
    for p,q in PQ:
        print(dp[p][q])

if __name__=='__main__':
    main()