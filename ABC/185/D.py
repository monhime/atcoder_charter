import sys
def input(): return sys.stdin.readline().rstrip()
import math
from functools import reduce

def main():
    n, m = map(int,input().split())
    A = list(map(int,input().split()))
    A.sort()
    Space = []
    pre_b = 0
    for a in A:
        if a - pre_b > 1:
            Space.append(a - pre_b - 1)
        pre_b = a
    if n - pre_b > 0:
        Space.append(n - pre_b)
    if Space == []:
        print(0)
        sys.exit()
    k = min(Space)
    ans = 0
    #rint(Space)
    for s in Space:
        ans += -(-s//k)
    print(ans)

if __name__=='__main__':
    main()