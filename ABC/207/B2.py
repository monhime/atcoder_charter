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
    
    a, b, c, d = map(int,input().split())
    # a + b*k <= d*c*k
    # a <= (b - d*c) * k
    flag = d*c - b
    if flag <= 0:
        print(-1)
        sys.exit()
    if a%flag == 0:
        print(a //flag)
    else:
        print(a//flag + 1)
    
    
if __name__=='__main__':
    main()