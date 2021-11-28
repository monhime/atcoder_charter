import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
from typing import List
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    A = list(map(int,input().split()))
    A_c = Counter(A)
    B = []
    for a_c_i in A_c.items():
        B.append(a_c_i)
    B.sort(reverse = True)
    x = -1
    for b in B:
        if b[1] == 1:
            continue
        if x == -1:
            if b[1] >= 4:
                print(b[0]**2)
                sys.exit()
            else:
                x = b[0]
        else:
            print(x* b[0])
            sys.exit()
    else:
        print(0)
    
if __name__=='__main__':
    main()