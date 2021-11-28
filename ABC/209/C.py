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
    C = sorted(list(map(int,input().split())))
    ans = 1
    for i, c in enumerate(C):
        ans = (ans * max(0, c - i)) % mod

    print(ans)
    
    
if __name__=='__main__':
    main()