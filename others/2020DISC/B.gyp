import sys
def input(): return sys.stdin.readline().rstrip()
from itertools import accumulate
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    A=list(accumulate(A))
    min_A=100000000000
    for a in A:
        min_A=min(min_A,abs(A[-1]/2-a))
    print(int(min_A*2))

if __name__=='__main__':
    main()