import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    h,n=map(int,input().split())
    lis=np.array([list(map(int,input().split())) for _ in range(n)])
    a_max=np.max(lis[:,0])
    dp=np.full(h+a_max+1,10**10)
    dp[0]=0
    for l in lis:
        dp[i:i+l[0]+1]=np.minimum(dp[i:i+l[0]+1],dp[i]+l[1])
    print(dp)
    print(dp[h])

if __name__=='__main__':
    main()