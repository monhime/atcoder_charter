import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
from fractions import gcd
def main():
    mod = 10**9 + 7
    inf = 10**10

    n = int(input())
    A = list(map(int,input().split()))
    ans = 0
    for l in range(n):
        min_seg = inf
        for r in range(l + 1, n + 1): # [l, r)
            min_seg = min(min_seg, A[r - 1])
            ans = max(ans, min_seg*(r - l))
    print(ans)
    
if __name__=='__main__':
    main()