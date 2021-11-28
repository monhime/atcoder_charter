import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math # math.inf
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    
    n = int(input())
    A = list(map(int,input().split()))

    sum_1, sum_2, sum_3 = 0, 0, 0
    sum_2_part = A[0]
    sum_3_part = A[0]**2
    for i in range(2, n + 1):
        a = A[i - 1]
        sum_1 += (i - 1) * a**2
        sum_2 += a * sum_2_part
        sum_3 += sum_3_part

        sum_2_part += a
        sum_3_part += a**2
    print(sum_1 - 2*sum_2 + sum_3)
    
if __name__=='__main__':
    main()