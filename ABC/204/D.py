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
    
    n  =int(input())
    T = sorted(list(map(int,input().split())), reverse = True)
    t_1, t_2 = T[0], 0
    c_idx = 1
    while c_idx < n:
        if t_1 > t_2:
            t_2 += T[c_idx]
        else:
            t_1 += T[c_idx]
        c_idx += 1
    print(max(t_1, t_2))
    
    
if __name__=='__main__':
    main()