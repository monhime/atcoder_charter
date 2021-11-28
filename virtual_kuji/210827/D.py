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
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    lis = []
    def f(idx, cunt, s):
        if idx == n:
            lis.append(s)
            return
        for i in range(cunt):
            f(idx + 1, cunt, s + chr(ord("a") + i))
        f(idx + 1, cunt + 1, s + chr(ord("a") + cunt))
    
    f(0, 0, "")
    lis.sort()
    for ss in lis:
        print(ss)

if __name__=='__main__':
    main()