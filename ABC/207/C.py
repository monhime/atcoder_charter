import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math # math.inf
def input(): return sys.stdin.readline().rstrip()
def flag_include_right(t):
    if t == 1 or t == 3:
        return True
    else:
        return False
def flag_include_left(t):
    if t == 1 or t == 2:
        return True
    else:
        return False

def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    TLR = [[int(_) for _ in input().split()] for i in range(n)]
    TLR.sort(key = itemgetter(1, 2))
    ans = 0
    for i in range(n - 1):
        i_right = TLR[i][2]
        f_i = flag_include_right(TLR[i][0])
        for j in range(i + 1, n):
            if TLR[j][1]> i_right:
                break
            f_j = flag_include_left(TLR[j][0])
            if (TLR[j][1] < TLR[i][2]) or ((f_i and f_j) and (TLR[j][1] == TLR[i][2])):
                ans += 1
    print(ans)

if __name__=='__main__':
    main()