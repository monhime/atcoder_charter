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
    
    n = float(input())
    x_0, y_0 = map(float,input().split())
    x_o, y_o = map(float,input().split())
    x = (x_0 - x_o)*math.cos(2.0*math.pi/n)/2.0\
        - (y_0 - y_o)*math.sin(2.0*math.pi/n)/2.0\
            + (x_0 + x_o)/2.0
    y = (x_0 - x_o)*math.sin(2.0*math.pi/n)/2.0\
        + (y_0 - y_o)*math.cos(2.0*math.pi/n)/2.0\
            + (y_0 + y_o)/2.0
    print(x, y)

if __name__=='__main__':
    main()