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
    inf = 10**10
    
    n, m = map(int,input().split())
    AB = [[int(_) for _ in input().split()] for i in range(m)]
    k = int(input())
    CD = [[int(_) for _ in input().split()] for i in range(k)]

    Flag_left = list(product([True, False], repeat = k))
    ans = 0
    for F in Flag_left:
        # print(F)
        Flag_ball = [False] * n # ボールがあるかどうか
        for i, f in enumerate(F):
            if f:
                Flag_ball[CD[i][0] - 1] = True
            else:
                Flag_ball[CD[i][1] - 1] = True
        ans_p = 0
        for a, b in AB:
            ans_p += Flag_ball[a - 1] and Flag_ball[b - 1]
        ans = max(ans, ans_p)
        # print(Flag_ball)
    print(ans)
    
if __name__=='__main__':
    main()