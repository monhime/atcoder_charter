from os import initgroups, linesep
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
    B = list(map(int,input().split()))
    if sum(A) < sum(B):
        print(-1)
        sys.exit()
    D = [a - b for a, b in zip(A, B)]
    D.sort()
    sum_m = 0
    ans = 0
    for d in D:
        if d < 0:
            sum_m += -d
            ans += 1
        else:
            break
    if sum_m == 0:
        print(0)
        sys.exit()
    for i in range(n - 1, -1, -1):  
        if sum_m <= D[i]:
            print(ans + 1)
            sys.exit()
        else:
            sum_m -= D[i]
            ans += 1
    
    
if __name__=='__main__':
    main()