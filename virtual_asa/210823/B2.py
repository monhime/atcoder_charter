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
    S = list(map(int,input().split()))
    T = list(map(int,input().split()))
    L = [-1] * n
    L[0] = T[0]
    for i in range(1, n):
        L[i] = min(L[i - 1] + S[i - 1], T[i])
    L[0] = min(L[0], L[-1] + S[-1])
    print(L[0])
    for i in range(1, n):
        L[i] = min(L[i], L[i - 1] + S[i - 1])
        print(L[i])
    
    
if __name__=='__main__':
    main()