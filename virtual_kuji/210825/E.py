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
    
    n, t = map(int,input().split())
    A = sorted(list(map(int,input().split())))
    
    A_left = [0] * (1 << (n//2))
    for bit in range(1 << n//2):
        sum_a = 0
        for i in range(n//2):
            mask = 1 << i
            if bit & mask:
                sum_a += A[i]
        A_left[bit] = sum_a

    A_right = [0] * (1 << (n - n//2))
    for bit in range(1 << (n - n//2)):
        sum_a = 0
        for i in range(n - n//2):
            mask = 1 << i
            if bit & mask:
                sum_a += A[i + n//2]
        A_right[bit] = sum_a
    
    # print(A_left)
    # print(A_right)
    A_right.sort()
    ans = 0
    for a_l in A_left:
        if a_l > t:
            continue 
        ans = max(ans, a_l + A_right[max(bisect_right(A_right, t - a_l) - 1, 0)])
    print(ans)

if __name__=='__main__':
    main()