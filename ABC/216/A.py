import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    a = float(input())
    x = int(a // 1)
    y = int((a - x)*10)
    if y <= 2:
        print(str(x) + "-")
    elif y <= 6:
        print(str(x))
    else:
        print(str(x) + "+")

    
    
if __name__=='__main__':
    main()