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
    
    n_s = input()
    keta = len(n_s)
    if keta % 2 == 1:
        print(10**(keta//2) - 1)
    else:
        ans = 0
        n_s_half = n_s[:keta//2]
        if n_s_half <= n_s[keta//2:]:
            print(n_s_half)
        else:
            print(int(n_s_half) - 1)
    
if __name__=='__main__':
    main()