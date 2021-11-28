import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
from operator import mul
from functools import reduce
def cmb1(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    A_c=Counter(A)

    combi=0
    for ac in A_c.items():
        if ac[1]>=2:
            combi+=cmb1(ac[1],2)
    for i in range(n):
        print(combi-(A_c[A[i]]-1))



if __name__=='__main__':
    main()