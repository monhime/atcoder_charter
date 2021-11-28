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
    
    p = int(input())
    C = reversed([math.factorial(n) for n in range(1, 11)])
    ans = 0
    for c in C:
        ans += p//c
        p = p%c
    print(ans)


    
    
if __name__=='__main__':
    main()