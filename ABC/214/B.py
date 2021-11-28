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
    
    s, t = map(int,input().split())
    ans = 0
    for a in range(s + 1):
        for b in range(s + 1):
            if a + b > s:
                break
            for c in range(s + 1):
                if a + b + c > s:
                    break
                if a*b*c <= t:
                    ans += 1
    print(ans)
    
    
if __name__=='__main__':
    main()