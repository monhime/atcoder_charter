import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    A=list(map(int,input().split()))
    X,Y=[0]*n,[0]*n
    for i in range(n):
        X[i]=i+A[i]
        Y[i]=i-A[i]
    set_x=set(X)
    yc=Counter(Y)
    xc=Counter(X)
    ans=0
    for x in set_x:
        ans+=xc[x]*yc[x]
    print(ans)

if __name__=='__main__':
    main()