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
    A_abs = [abs(a) for a in A]
    cunt_0 = 0
    cunt_m = 0
    for a in A:
        if a == 0:
            cunt_0 += 1
        elif a < 0:
            cunt_m += 1
    if cunt_0 > 0 or cunt_m % 2 == 0:
        print(sum(A_abs))
    else:
        print(sum(A_abs) - 2*min(A_abs))
    
    
if __name__=='__main__':
    main()