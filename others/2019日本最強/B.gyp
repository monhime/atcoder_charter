import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter,defaultdict
mod=10**9+7
def main():
    n,k=map(int,input().split())
    A=[int(_) for _ in input().split()]
    ac=Counter(A)
    aci=list(ac.items())
    aci.sort(reverse=True)
    nn=len(aci)
    aciv_cum=[0]*nn
    m2=defaultdict(int)
    for i in range(1,nn):
        aciv_cum[i]=aciv_cum[i-1]+aci[i-1][1]
        m2[aci[i][0]]+=aciv_cum[i]
    ans=0
    for i,a in enumerate(A):
        b=m2[a]
        x=0
        for j in range(i):
            if A[j]>a:
                x+=1
        ans+=k*(2*x+(k-1)*b)//2%mod
    print(ans%mod)

if __name__=='__main__':
    main()