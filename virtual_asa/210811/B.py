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
    
    n, k = map(int,input().split())
    if n < k:
        print(min(n, k - n))
    else:
        print(min(n - (n//k)*k, (n//k + 1)*k - n))
    
    
if __name__=='__main__':
    main()