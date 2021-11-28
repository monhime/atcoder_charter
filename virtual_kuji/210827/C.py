from os import initgroups
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
    k = sum(A)//n
    ans_1 = 0
    for a in A:
        ans_1 += (a - k)**2
    ans_2 = 0
    for a in A:
        ans_2 += (a - k - 1)**2
    print(min(ans_1, ans_2))
    
if __name__=='__main__':
    main()  