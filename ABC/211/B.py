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
    
    S = [input() for _ in range(4)]
    if S.count("H") * S.count("2B") * S.count("3B") * S.count("HR") == 1:
        print("Yes")
    else:
        print("No")
    
    
if __name__=='__main__':
    main()