import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, m = map(int,input().split())
    AB = [[0]*2 for _ in range(m)]
    for i in range(m):
        a, b = map(int,input().split())
        if a > b:
            a, b = b, a
        AB[i][0], AB[i][1] = a - 1, b - 1
    cur_right = AB[0][1]
    cur_idx = 0
    other_idx = 1
    ans = 0
    while True:
        while True:
            other_idx += 1
            if other_idx >= n:
                ans += 1
                break
            other_left = AB[other_idx][0]
            if other_left >= cur_right:
                ans += 1
                cur_idx = other_idx
                break
        cur_right = AB[cur_idx][1]

    
    
if __name__=='__main__':
    main()