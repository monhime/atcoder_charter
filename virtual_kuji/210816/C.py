import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    ans = 2
    k = 2
    while k*(k+1)//2 <= n:
        if k % 2:
            if n % k == 0:
                ans += 2
        else:
            if (2*n)%(2*k)==k:
                ans += 2
        k += 1

    print(ans)
    
if __name__=='__main__':
    main()