import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    x, y = map(int,input().split())
    # print(math.floor(math.log(y/x, 2)) + 1)
    k = 0
    while True:
        if 2**k * x >y:
            print(k)
            break
        k += 1
    
    
if __name__=='__main__':
    main()