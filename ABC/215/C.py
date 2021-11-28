import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
from typing import Container
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    s, k = input().split()
    k = int(k)
    S_lis = list(permutations(list(s)))
    S_lis_2 = ["".join(s) for s in S_lis]
    S_lis_2_c = Counter(S_lis_2)
    print(sorted(S_lis_2_c.keys())[k - 1])

if __name__=='__main__':
    main()