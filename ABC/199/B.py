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
    
    n = int(input())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    print(max(min(B) - max(A) + 1, 0))
    
    
if __name__=='__main__':
    main()