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
    inf = 10**10
    
    n, m = map(int,input().split())
    A = sorted(list(map(int,input().split())))
    BC = [tuple(map(int,input().split())) for i in range(m)]
    BC.sort(reverse = True, key = itemgetter(1))
    large_b_set = 0
    large_b_part = 0
    ans = 0
    for a in A:
        if large_b_set == m or a >= BC[large_b_set][1]: #使い切った or 小さい
            ans += a
            continue
        
        ans += BC[large_b_set][1] # 書き換え
        large_b_part += 1
        if BC[large_b_set][0] == large_b_part: # 使い切った
            large_b_set += 1
            large_b_part = 0
    print(ans)
    
    
if __name__=='__main__':
    main()