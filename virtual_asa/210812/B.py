import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    
    n = int(input())
    A = list(map(int,input().split()))
    ans_1 = 0
    sum_a = 0
    max_A = -1
    for i, a in enumerate(A):
        max_A = max(max_A, a)
        sum_a += a
        ans_1 += sum_a
        print(ans_1 + (i + 1)*max_A)
    
    
if __name__=='__main__':
    main()