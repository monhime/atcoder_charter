import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math # math.inf
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    a, b, w = map(int,input().split())
    w *= 1000
    start = a
    last = b
    cunt = 1
    ans_min = inf
    ans_max = -1
    while start <= w:
        if start <= w and w <= last :
            if ans_min == inf:
                ans_min = cunt
            ans_max = max(ans_max, cunt)
        cunt += 1
        start += a
        last += b
    if ans_min == inf:
        print("UNSATISFIABLE")
    else:
        print(ans_min, ans_max)
    
if __name__=='__main__':
    main()