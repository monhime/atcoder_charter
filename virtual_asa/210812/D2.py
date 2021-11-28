import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math
def input(): return sys.stdin.readline().rstrip()

def main():
    inf = 10**9 + 7

    n, m, q = map(int,input().split())
    ABCD = [[int(_) for _ in input().split()] for i in range(q)]
    A = [0] * n
    global ans
    ans = 0
    def dfs(cu, lst):
        if (cu == n):
            tot = 0
            for i in range(q):
                if(A[ABCD[i][1] - 1] - A[ABCD[i][0] - 1] == ABCD[i][2]):
                    tot += ABCD[i][3]
            global ans
            ans = max(ans , tot)
            return
        for nxt in range(lst, m + 1):
            A[cu] = nxt
            dfs(cu + 1, nxt)

    dfs(0, 1)

    print(ans)

if __name__=='__main__':
    main()