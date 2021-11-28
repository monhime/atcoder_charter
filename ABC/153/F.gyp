import sys
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect
def main():
    n,d,a=map(int,input().split())
    XH=[list(map(int,input().split())) for i in range(n)]
    XH.sort()
    X,H=zip(*XH)
    right=[0]*n
    for i,x in enumerate(X):
        right[i]=bisect(X,x+2*d)
    damage=[0]*(n+1)
    ans=0
    for i,(x,h) in enumerate(XH):
        if i!=0:
            damage[i]+=damage[i-1]
        h-=damage[i]
        if h>0:
            cunt=-(-h//a)
            ans+=cunt
            damage[i]+=a*cunt
            damage[right[i]]-=a*cunt
    print(ans)


if __name__=='__main__':
    main()