import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    
    n = int(input())
    APX = [[int(_) for _ in input().split()] for i in range(n)]
    Y = [[0] * 2 for _ in range(n)]# 到着したときの在庫
    for i, (a, p, x) in enumerate(APX):
        Y[i][1] = max(x - a, 0)
        Y[i][0] = p
    Y.sort()
    for p, _x in Y:    
        if _x > 0:
            print(p)
            sys.exit()
    print(-1)
    
if __name__=='__main__':
    main()