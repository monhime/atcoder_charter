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
    
    a, b = map(int,input().split())

    ans = 0
    for i in range(8):
        ans += ((a%2) ^ (b%2))*2**i
        a //=2
        b //= 2
    print(ans)

    
    
if __name__=='__main__':
    main()