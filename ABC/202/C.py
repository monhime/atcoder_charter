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
    B = list(map(int,input().split()))
    C = list(map(int,input().split()))
    B_m = dict() # keyの値になりうるjの数
    for c in C:
        c -= 1
        B_m[B[c]] = B_m.get(B[c], 0) + 1
    A_c = Counter(A)
    ans = 0
    for A_c_i in A_c.items():
        ans += A_c_i[1]*B_m.get(A_c_i[0], 0)
    print(ans)

    
    
if __name__=='__main__':
    main()