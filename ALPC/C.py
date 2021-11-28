import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()

# Reference: https://qiita.com/R_olldIce/items/3e2c80baa6d5e6f3abe9
def floor_sum_unsigned(n, m, a, b):
    ans = 0
    while True:
        if a >= m:
            ans += n*(n - 1)*(a//m)//2
            a %= m
        if b >= m:
            ans += n*(b//m)
            b %= m
        y_max = a*n + b        
        if y_max < m: break
        n, b, m, a, = y_max//m, y_max%m, a, m
    return ans   
def floor_sum(n, m, a, b):
    ans = 0
    if a < 0:
        ans += n*(n-1)*(a//m)//2
        a %= m
    if b < 0:
        ans += n * (b // m)
        b %= m
    ans += floor_sum_unsigned(n, m, a, b)
    return ans

def main():
    t = int(input())
    for _ in range(t):
        n, m, a, b = map(int, input().split())
        print(floor_sum(n, m, a, b))   
    
    
if __name__=='__main__':
    main()