import sys
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect
def main():
    n,k=map(int,input().split())
    X=list(map(int,input().split()))
    zero=bisect(X,0)
    ans=10**9
    for i in range(k+1):
        if zero-i<0 or zero+k-i-1>=n:
            continue
        if i==0:
            ans=min(ans,X[zero+k-i-1])
        elif i==k:
            ans=min(ans,-X[zero-i])
        else:
            kyori_m=2*-X[zero-i]+X[zero+k-i-1]
            kyori_p=-X[zero-i]+2*X[zero+k-i-1]
            ans=min(ans,kyori_m,kyori_p)  
    print(ans)

if __name__=='__main__':
    main()