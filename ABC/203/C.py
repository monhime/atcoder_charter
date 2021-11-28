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
    mod = 10**9 + 7
    
    n, k = map(int,input().split())
    AB = [[int(_) for _ in input().split()] for i in range(n)]
    AB.sort()
    now_mura = 0
    now_k = k
    for a, b in AB: # 次，aへ
        if now_mura + now_k < a:
            print(now_mura + now_k)
            sys.exit()
        now_k -= a - now_mura
        now_k += b
        now_mura = a
    print(now_mura +  now_k)

    
    
if __name__=='__main__':
    main()