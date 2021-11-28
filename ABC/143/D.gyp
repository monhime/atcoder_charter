import sys
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect_left
def main():
    n=int(input())
    L=[int(_) for _ in input().split()]
    L.sort()
    ans=0
    for a in range(n-2):
        for b in range(a+1,n-1):
            ans+=bisect_left(L,L[a]+L[b])-b-1
    print(ans)


if __name__=='__main__':
    main()