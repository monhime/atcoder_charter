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
    m = dict()
    for a in range(2, math.floor(math.sqrt(n)) + 1):
        x = a
        for _ in range(2, math.floor(math.log(n, a)) + 1):
            x *= a
            m[x] = m.get(x, 0) + 1
    print(n - len(m))
    
if __name__=='__main__':
    main()