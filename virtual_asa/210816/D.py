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
    
    s = input()
    n = len(s)
    left_idx = 0
    right_idx = n - 1
    ans = 0
    while left_idx <= right_idx:
        if s[left_idx] == s[right_idx]:
            left_idx += 1
            right_idx -=1
        elif s[left_idx] =="x":
            left_idx +=1
            ans +=1
        elif s[right_idx] == "x":
            ans += 1
            right_idx -=1
        else:
            print(-1)
            sys.exit()
    print(ans)
    
if __name__=='__main__':
    main()