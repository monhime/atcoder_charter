import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    n,k=map(int,input().split())
    H=list(map(int,input().split()))
    H.extend([0]*k)
    H=np.array(H)
    dp=np.full(n+k,10**12) #足湯iまでに着くまでに支払うコストの総和の最小値
    dp[0]=0
    for i in range(n):
        dp[i+1:i+k+1]=np.minimum(dp[i+1:i+k+1],dp[i]+np.abs(H[i+1:i+k+1]-H[i]))
    print(dp[n-1])
if __name__=='__main__':
    main()