import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 998244353
    inf = 10**10
    
    n = int(input())
    F = list(map(int,input().split()))
    graph = [0]*n
    for i, f in enumerate(F):
        graph[i] = f - 1
    memo = [-1]*n
    def f(i, par):
        next = graph[i]
        if memo[next] == par:
            return True
        if memo[next] != -1 and memo[next] != i:
            return False 
        memo[next] = par
        return f(next, par)

    cunt = 0
    for i in range(n):
        if memo[i] == -1:
            memo[i] = i
            if f(i, i):
                cunt += 1
    print((pow(2, cunt, mod) - 1)%mod)

    
    
if __name__=='__main__':
    main()