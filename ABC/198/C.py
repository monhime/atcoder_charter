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
    
    r, x, y = map(int,input().split())
    kyori_2 = x**2 + y**2
    ans = math.sqrt(kyori_2/r**2)
    ans_round = round(math.sqrt(kyori_2/r**2))
    if math.isclose(ans, ans_round):
        print(ans_round)
    elif ans > 1.0:
        print(math.ceil(ans))
    else:
        print(2)

    
    
if __name__=='__main__':
    main()