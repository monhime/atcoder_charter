import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, m = map(int,input().split())
    iPY = []
    for i in range(m):
        p, y = map(int,input().split())
        iPY.append([i, p, y])
    iPY.sort(key = itemgetter(2))
    P_count = [0]*n
    S_lis = [None for _ in range(m)]
    for i, p, _ in iPY:
        ans_p = P_count[p - 1] + 1
        S_lis[i] = f"{p:06}{ans_p:06}"
        P_count[p - 1] += 1
    for s in S_lis:
        print(s)
    
if __name__=='__main__':
    main()