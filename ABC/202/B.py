import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    
    s = input()
    A = ['6' if c == '9' else \
            '9' if c == '6' else\
            c for c in s]
    print("".join(reversed(A)))
    
if __name__=='__main__':
    main()