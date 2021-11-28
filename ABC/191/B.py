import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    
    n, x = map(int,input().split())
    A = list(map(int,input().split()))
    B = [0]*(n - A.count(x))
    i = 0
    for a in A:
        if a != x:
            B[i] = a
            i += 1
    print(' '.join(map(str, B)))
    
if __name__=='__main__':
    main()