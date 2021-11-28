import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,k=map(int,input().split())
    dp=[[0,0] for _ in range(n+1)] #最大iで，全てiか，一部iか
    if k%2==0:
        dp[k//2][0]=1
        for i in range(n-k//2+1):
            dp[i+k//2][0]=max(dp[i][0],dp[i+k//2][0]) 
        for i in range(n-k+1):
            dp[i+k][1]=dp[i][0]*6
    else:
        dp[k][0]=1
        for i in range(n-k+1):
            dp[i+k][0]=max(dp[i][0],dp[i+k][0])
            dp[i+k][1]=dp[i][0]*6

    
    print(dp)
    print(sum(x+y for x,y in dp))
    
            

if __name__=='__main__':
    main()