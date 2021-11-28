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
    inf = 10**11
    
    a, b, q = map(int,input().split())
    s = [int(input())for _ in range(a)]
    t = [int(input())for _ in range(b)]


    for i in range(q):
        q = int(input())
        s_i = bisect_left(s, q)
        if s_i >= a:
            kyori_sm = q - s[-1]
            kyori_sp = inf
        elif q < s[0]:
            kyori_sp = s[s_i] - q
            kyori_sm = inf
        elif q == s[s_i]:
            kyori_sp = 0
            kyori_sm = 0
        else:
            kyori_sp = s[s_i] - q
            kyori_sm = q - s[s_i - 1]
        
        t_i = bisect_left(t, q)
        if t_i >= b:
            kyori_tm = q - t[-1]
            kyori_tp = inf
        elif q < t[0]:
            kyori_tp = t[t_i] - q
            kyori_tm = inf
        elif q == t[t_i]:
            kyori_tp = 0
            kyori_tm = 0
        else:
            kyori_tp = t[t_i] - q
            kyori_tm = q - t[t_i - 1]
        
        ans = inf
        if kyori_sp <= kyori_tp:
            ans = min(ans, min(2*kyori_sp+kyori_tm, kyori_tp))
        else:
            ans = min(ans, min(2*kyori_tp+kyori_sm, kyori_sp))
        if kyori_sm <= kyori_tm:
            ans = min(ans, min(2*kyori_sm+kyori_tp, kyori_tm))
        else:
            ans = min(ans, min(2*kyori_tm+kyori_sp, kyori_sm))
        print(ans)
if __name__=='__main__':
    main()