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
    
    n_s = input()
    len_n = len(n_s)
    n = int(n_s)

    if len_n <4:
        print(0)
    elif len_n >= 4 and len_n < 7:
        print(n - 999)
    elif len_n >= 7 and len_n < 10:
        print(n - 999 + n - 999999)
    elif len_n >= 10 and len_n < 13:
        print(n - 999 + n - 999999 + n - 999999999)
    elif len_n >= 13 and len_n < 16:
        print(n - 999 + n - 999999 + n - 999999999 + n - 999999999999)    
    else:
        print(n - 999 + n - 999999 + n - 999999999 + n - 999999999999 + n - 999999999999999)
    
if __name__=='__main__':
    main()