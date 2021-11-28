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
    
    n, k = map(int,input().split())
    A = list(map(int,input().split()))
    A_c = Counter(A)
    A_c_v = sorted(A_c.values())
    len_A_c_v = len(A_c_v)
    print(sum(A_c_v[:(len_A_c_v - k)]))
    
    
if __name__=='__main__':
    main()