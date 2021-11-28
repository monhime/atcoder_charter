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
    
    n, k  = map(int,input().split())
    A = list(map(int,input().split()))
    cunt_0 = 0
    left_a = A[0]
    for i in range(k):
        if A[i] == 0:
            cunt_0 += 1
    for i in range(k , n):
        if A[i - k] < A[i]:
            print("Yes")
        else:
            print("No")
    
if __name__=='__main__':
    main()