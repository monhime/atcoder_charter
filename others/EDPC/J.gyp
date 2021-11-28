import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=list(map(int,input().split()))
    #1個がi個，2個がj個，3個がk個
    dp=[[[0.0]*(n+1) for j in range(n+1)]for i in range(n+1)]
    max_i,max_j=A.count(1),A.count(2)
    max_k=n-max_i-max_j
    for k in range(max_k+1):
        for j in range(max_j+max_k+1):
            for i in range(min(max_i+max_j+max_k+1,n-(j+k)+1)):
                if i+j+k==0:continue
                res=n
                if i>0:res+=dp[i-1][j][k]*i
                if j>0:res+=dp[i+1][j-1][k]*j
                if k>0:res+=dp[i][j+1][k-1]*k
                res/=i+j+k
                dp[i][j][k]=res
    print(dp[max_i][max_j][max_k])

if __name__=='__main__':
    main()