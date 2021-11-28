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
    bi_n = bin(n)[2:]
    ans = ""
    for c in bi_n:
        if c == '1':
            ans += "AB"
        else:
            ans += "B"
    print(ans[:-1])
    
    
if __name__=='__main__':
    main()