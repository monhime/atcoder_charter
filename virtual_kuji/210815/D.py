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
    
    n = int(input())
    LR = [[0]*2 for _ in range(n)]
    for i in range(n):
        x, l = map(int,input().split())
        LR[i][0], LR[i][1]= x - l, x + l
    LR.sort(key = itemgetter(1))
    ans = 0
    max_r = -inf
    for l, r in LR:
        if max_r <= l:
            ans += 1
            max_r = r
    print(ans)
    
if __name__=='__main__':
    main()