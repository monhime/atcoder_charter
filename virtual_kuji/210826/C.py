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
    
    n = int(input())
    graph = [0]*n
    for i in range(n):
        a = int(input())
        graph[i] = a - 1
    visited = [False]*n
    visited[0] = True
    cur_b = 0
    cunt = 1
    while True:
        visited[cur_b] = True
        next_b = graph[cur_b]
        if visited[next_b]:
            print(-1)
            sys.exit()
        if next_b == 1:
            print(cunt)
            sys.exit()
        cunt += 1
        cur_b = next_b
 
    
    
if __name__=='__main__':
    main()