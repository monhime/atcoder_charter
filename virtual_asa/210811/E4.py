import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
    
def main():
    mod = 10**9 + 7
    
    n = int(input())
    # AGCT: 0123
    # ダメ：AGC (012)，ACG (021)，GAC (102)
    # dp[size][i][j][k] 
    dp = [[[[0] * 4 for _ in range(4)] for _ in range(4)] for _ in range(n + 1)]
    for i in range(4):
        for j in range(4):
            for k in range(4):
                dp[3][i][j][k] = 1
    dp[3][0][1][2] = 0
    dp[3][0][2][1] = 0
    dp[3][1][0][2] = 0
    for size in range(3, n):
        for i in range(4):
            for j in range(4):
                for k in range(4):
                    for new_s in range(4):
                        # AGC，ACG，GAC，AGxC
                        if (new_s == 0 and i == 1 and j == 2) or \
                            (new_s == 0 and i == 2 and j == 1) or \
                            (new_s == 1 and i == 0 and j == 2) or \
                            (new_s == 0 and i == 1 and k == 2) or \
                            (new_s == 0 and j == 1 and k == 2):
                            continue
                        dp[size + 1][new_s][i][j] = (dp[size + 1][new_s][i][j] + dp[size][i][j][k]) %mod

    ans = 0
    for i in range(4):
        for j in range(4):
            for k in range(4):
                ans = (ans + dp[n][i][j][k]) %mod
    print(ans)
                
if __name__=='__main__':
    main()