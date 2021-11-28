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
    
    A = [int(input())for _ in range(5)]
    mod_A = [((a - 1) % 10, a) for a in A]
    mod_A.sort()
    ans = 0
    for i, (ma, a) in enumerate(mod_A):
        if i == 0:
            ans += a
        else:
            ans += -(-a//10)*10
    print(ans)
    
    
if __name__=='__main__':
    main()