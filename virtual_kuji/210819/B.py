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
    C = list(map(int,input().split()))

    A_c = Counter(A)
    C_c = Counter(C)
    B_dict = dict()
    for c in C:
        B_dict[B[c - 1]] = B_dict.get(B[c - 1], 0) + 1
    ans = 0
    for b in B_dict.items():
        ans += A_c[b[0]] * b[1]

    print(ans)
    
if __name__=='__main__':
    main()