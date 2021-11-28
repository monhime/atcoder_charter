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
    
    n = int(input())

    if n % 2:
        print(0)
    else:
        ans = 0
        k = 1
        while n >= 5**k:
            ans += n //5**k//2
            k += 1
        print(ans)
    
if __name__=='__main__':
    main()