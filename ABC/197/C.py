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
    ans = inf
    for bit in range(1 << (n - 1)):#2**n通りのbit_n番目を探索
        ans_part = 0
        cunt_or = 0
        for i in range(n - 1):
            mask = 1 << i 
            cunt_or |= A[i]
            if bit & mask: # bitのi桁目が1なら仕切り
                ans_part ^= cunt_or
                cunt_or = 0
        cunt_or |= A[-1]
        ans_part ^= cunt_or
        ans = min(ans, ans_part)
    print(ans)

    
if __name__=='__main__':
    main()