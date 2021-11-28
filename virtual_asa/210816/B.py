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
    inf = 10**10
    
    n = int(input())
    A = list(map(int,input().split()))

    A_c = Counter(A)
    sum_part = 0
    ans = 0
    for a_c_v in A_c.values():
        ans += a_c_v * sum_part
        sum_part += a_c_v
        
    print(ans)
    
    
if __name__=='__main__':
    main()