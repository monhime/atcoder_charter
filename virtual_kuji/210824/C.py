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
    A = list(map(int,input().split()))
    A_c = Counter(A)
    ans = 0
    for a_c_k, a_c_v in A_c.items():
        if a_c_v >= a_c_k:
            ans += a_c_v - a_c_k
        else:
            ans += a_c_v
    print(ans)
    
    
if __name__=='__main__':
    main()