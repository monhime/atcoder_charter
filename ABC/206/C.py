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
    A_c = Counter(A)
    ans = n*(n-1)//2
    for A_cv in A_c.values():
        ans -= A_cv*(A_cv - 1)//2
    print(ans)
    
    
if __name__=='__main__':
    main()