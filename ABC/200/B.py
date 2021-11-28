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
    
    n, k = map(int,input().split())
    n_s = str(n)
    for _ in range(k):
        if n % 200 == 0:
            n //= 200
            n_s = str(n)
        else:
            n_s += "200"
            n = int(n_s)
    print(n_s)
    
    
if __name__=='__main__':
    main()