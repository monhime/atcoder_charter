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
    
    n = int(input())
    UVW = [tuple(map(int,input().split())) for i in range(n)]
    graph = [[] for _ in range(n)]
    for u, v, w in UVW:
        graph[u - 1].append((v - 1, w))
        graph[v - 1].append((u - 1, w))
    
    def dfs(n):
        
    
    for i in range(n):

    
if __name__=='__main__':
    main()