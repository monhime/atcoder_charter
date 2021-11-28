import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    s = list(input() )
    q = int(input())
    TAB = [tuple(map(int,input().split())) for i in range(q)]
    swap_flag = False
    for t, a, b in TAB:
        if t == 2:
            swap_flag ^= True
            continue
        _a = a - 1
        _b = b - 1
        if swap_flag:
            _a = (_a + n) %(2*n)
            _b = (_b + n) % (2*n)
        s[_a], s[_b] = s[_b], s[_a]
    if swap_flag:
        print("".join(s[n:]+s[:n]))
    else:
        print("".join(s))


if __name__=='__main__':
    main()