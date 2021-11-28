import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n,k=map(int,input().split())
    A=[int(input())for _ in range(n)]
    cunt=1
    ccunt=Counter()
    for i in range(1,n):
        if A[i]>A[i-1]:
            cunt+=1
        else:
            ccunt[cunt]+=1
            cunt=1
    ccunt[cunt]+=1
    cci=list(ccunt.items())
    ans=0
    for c in cci:
        if c[0]>=k:
            ans+=(c[0]-k+1)*c[1]
    print(ans)

if __name__=='__main__':
    main()