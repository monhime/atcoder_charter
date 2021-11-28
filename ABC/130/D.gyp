import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import accumulate
import bisect
def main():
    n,k=map(int,input().split())
    A=[int(_) for _ in input().split()]
    A_cum=list(accumulate(A))
    ans=n-bisect.bisect_left(A_cum,k)
    for i in range(n):
        ans+=n-bisect.bisect_left(A_cum,k+A_cum[i])
    print(ans)

if __name__=='__main__':
    main()