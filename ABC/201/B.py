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
    ST = [[_ for _ in input().split()] for i in range(n)]
    T = [[0]*2 for _ in range(n)] # 高さ，何番目の山？
    T = [[int(t), i] for i, (_, t) in enumerate(ST)]
    print(ST[sorted(T, reverse=True)[1][1]][0])

    
    
if __name__=='__main__':
    main()