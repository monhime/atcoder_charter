import sys
def input(): return sys.stdin.readline().rstrip()
import numpy as np
def main():
    n=int(input())
    A=np.array(list(map(int,input().split())))
    mod=10**9+7
    ans=0
    for i in range(60):
        c=np.count_nonzero(A&1)
        A>>=1
        ans+=(c*(n-c))<<i%mod
    print(ans%mod)

if __name__=='__main__':
    main()