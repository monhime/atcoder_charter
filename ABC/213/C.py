import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    h, w, n = map(int,input().split())
    iABrc = [[0, 0, 0, 0, 0] for _ in range(n)]
    for i in range(n):
        iABrc[i][0] = i + 1
        iABrc[i][1], iABrc[i][2] = map(int,input().split())
    iABrc.sort(key = itemgetter(1))
    cunt = 0
    pre_r = -1
    for i in range(n):
        if pre_r < iABrc[i][1]:
            cunt += 1
            pre_r = iABrc[i][1]
        iABrc[i][3] = cunt 
    iABrc.sort(key = itemgetter(2))
    cunt = 0
    pre_c = -1
    for i in range(n):
        if pre_c < iABrc[i][2]:
            cunt += 1
            pre_c = iABrc[i][2]
        iABrc[i][4] = cunt
    iABrc.sort(key=itemgetter(0))
    for i in range(n):
        print(iABrc[i][3], iABrc[i][4])
    
    
if __name__=='__main__':
    main()