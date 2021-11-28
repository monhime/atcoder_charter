import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    D=[int(_) for _ in input().split()]
    dc=Counter(D)
    mod,ans=998244353,1
    if D[0]!=0 or dc[0]!=1:
        print(0)
        sys.exit()
    for i,_ in enumerate(list(dc.items())):
        if i>1:
            ans*=dc[i-1]**dc[i]%mod
    print(ans%mod)

if __name__=='__main__':
    main()