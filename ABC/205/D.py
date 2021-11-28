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
    
    n, q = map(int,input().split())
    A = list(map(int,input().split()))
    B = [(1, 0)]
    left = 0
    for a in A:
        B.append((a - B[-1][1], B[-1][1] + 1))
        left += 1
    len_B = len(B)

    def f(k):
        left = 0
        right = len_B
        while right - left >1:
            mid = (left + right)//2
            if B[mid][0] <= k:
                left = mid
            else:
                right = mid
        return B[left][1] # 0要素目がk以下の最後の要素の1要素目

    for _ in range(q):
        k = int(input())
        print(k + f(k))

if __name__=='__main__':
    main()