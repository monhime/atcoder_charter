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
    
    _ = input()
    s = input()

    for i, c in enumerate(s):
        if c == '1':
            if i%2 == 0:
                print("Takahashi")
            else:
                print("Aoki")
            sys.exit()

    
if __name__=='__main__':
    main()