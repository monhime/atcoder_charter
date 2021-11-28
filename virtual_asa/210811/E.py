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
    # 0: AA, 1: AG，2: AC，3: AT
    # 4: GA, 5: GG，6: GC，7: GT
    # 8: CA, 9: CG，10: CC，11: CT
    # 12: TA, 13: TG，14: TC，15: TT
    dp = [[0] * (n - 1) for _ in range(16)] # j列目：j+2 列目までの状態数
    for i in range(16):
        dp[i][0] = 1
    for j in range(1, n - 1):
        # A
        dp[0][j] = dp[0][j - 1] + dp[4][j - 1]+ dp[8][j - 1]+ dp[12][j - 1]
        dp[1][j] = dp[0][j - 1] + dp[4][j - 1]+ dp[8][j - 1]+ dp[12][j - 1]
        dp[2][j] = dp[0][j - 1] + dp[8][j - 1]+ dp[12][j - 1]
        dp[3][j] = dp[0][j - 1] + dp[4][j - 1]+ dp[8][j - 1]+ dp[12][j - 1]
        dp[4][j] = dp[1][j - 1] + dp[5][j - 1]+ dp[9][j - 1]+ dp[13][j - 1]
        dp[5][j] = dp[1][j - 1] + dp[5][j - 1]+ dp[9][j - 1]+ dp[13][j - 1]
        dp[6][j] = dp[5][j - 1]+ dp[9][j - 1]+ dp[13][j - 1]
        dp[7][j] = dp[1][j - 1] + dp[5][j - 1]+ dp[9][j - 1]+ dp[13][j - 1]
        dp[8][j] = dp[2][j - 1] + dp[6][j - 1]+ dp[10][j - 1]+ dp[14][j - 1]
        dp[9][j] = dp[6][j - 1]+ dp[10][j - 1]+ dp[14][j - 1]
        dp[10][j] = dp[2][j - 1] + dp[6][j - 1]+ dp[10][j - 1]+ dp[14][j - 1]
        dp[11][j] = dp[3][j - 1] + dp[7][j - 1]+ dp[11][j - 1]+ dp[15][j - 1]
        dp[12][j] = dp[2][j - 1] + dp[6][j - 1]+ dp[10][j - 1]+ dp[14][j - 1]
        dp[13][j] = dp[2][j - 1] + dp[6][j - 1]+ dp[10][j - 1]+ dp[14][j - 1]
        dp[14][j] = dp[2][j - 1] + dp[6][j - 1]+ dp[10][j - 1]+ dp[14][j - 1]
        dp[15][j] = dp[2][j - 1] + dp[6][j - 1]+ dp[10][j - 1]+ dp[14][j - 1]
    ans = 0
    for i in range(16):
        ans += dp[i][n - 2]
    print(ans)
    
if __name__=='__main__':
    main()