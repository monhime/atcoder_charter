import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    ABC=[tuple(map(int,input().split())) for i in range(n)]
    dp=[[0,0,0]for _ in range(n+1)] #i日目にjをするときの幸福度の総和
    for i in range(n):
        ni=i+1
        dp[ni][0]=max(dp[i][1],dp[i][2])+ABC[ni-1][0]
        dp[ni][1]=max(dp[i][0],dp[i][2])+ABC[ni-1][1]
        dp[ni][2]=max(dp[i][0],dp[i][1])+ABC[ni-1][2]
    print(max(dp[n]))

if __name__=='__main__':
    main()