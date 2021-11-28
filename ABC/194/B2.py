from os import initgroups
import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    
    n = int(input())
    AB = [[int(_) for _ in input().split()] for i in range(n)]
    iAB = [[i, a, b] for i, (a, b) in enumerate(AB)]
    min_ApB = sorted([a + b for a, b in AB])[0]
    AB_amin = sorted(iAB, key = itemgetter(1))
    AB_bmin = sorted(iAB, key = itemgetter(2))
    if AB_bmin[0][0] == AB_amin[0][0]:
        min_a = max(AB_amin[0][1], AB_bmin[1][2])
        min_b = max(AB_amin[1][1], AB_bmin[0][2])
        print(min(min(min_ApB, min_a), min_b))
    else:
        min_ab = max(AB_amin[0][1], AB_bmin[0][2])
        print(min(min_ApB, min_ab))

if __name__=='__main__':
    main()