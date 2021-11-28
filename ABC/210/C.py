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
    
    n, k = map(int,input().split())
    C = list(map(int,input().split()))
    m = dict()
    cunt = 0 # 長さkの間の種類の数
    ans = 0
    for i in range(k):
        if m.get(C[i], 0) == 0:
            cunt += 1
            ans = max(ans, cunt)
        m[C[i]] = m.get(C[i], 0) + 1
    
    for i in range(k, n):
        if C[i] == C[i - k]:
            continue
        if m.get(C[i], 0) == 0:
            cunt += 1
        if m[C[i - k]] == 1:
            cunt -= 1
        ans = max(ans, cunt)
        m[C[i]] = m.get(C[i], 0) + 1
        m[C[i - k]] -= 1
    print(ans)
    
if __name__=='__main__':
    main()