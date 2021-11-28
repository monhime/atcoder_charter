import sys
import numpy as np
def input(): return sys.stdin.readline().rstrip()
from bisect import bisect_left,bisect
from itertools import accumulate
def main():
    n = int(input())
    AB = [tuple(map(int,input().split())) for i in range(n)]
    C = [0]*n
    sum_a = 0
    for i, (a, b) in enumerate(AB):
        C[i] = a*2 + b
        sum_a += a
    C.sort(reverse = True)
    C = list(accumulate(C))
    print(bisect(C, sum_a) + 1)





if __name__=='__main__':
    main()