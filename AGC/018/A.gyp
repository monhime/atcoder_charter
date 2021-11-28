import sys
def input(): return sys.stdin.readline().rstrip()
import fractions
from functools import reduce
def gcd(*numbers):
    return reduce(fractions.gcd, numbers)
def main():
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    gcd_a=gcd(*A)
    if k%gcd_a==0 and max(A)>=k:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")


if __name__=='__main__':
    main()