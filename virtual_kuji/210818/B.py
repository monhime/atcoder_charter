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
    
    n, k = map(int,input().split())
    C = list(map(int,input().split()))
    m = dict()
    for i in range(k):
        m[C[i]] = m.get(C[i], 0) + 1
    ans = len(m)
    cunt = ans
    for i in range(k, n):
        if C[i] == C[i - k]:
            continue
        if m.get(C[i], 0) == 0:
            if m[C[i - k]] > 1:
                cunt += 1
                ans = max(ans, cunt)
        else:
            if m[C[i - k]] == 1:
                cunt -= 1
        m[C[i]] = m.get(C[i], 0) + 1
        m[C[i - k]] -= 1
    print(ans)

    
    
if __name__=='__main__':
    main()