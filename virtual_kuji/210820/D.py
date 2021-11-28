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
    
    n = int(input())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    AB = [a - b for a, b in zip(A, B)]
    cunt_a, cunt_b, cunt_ab = 0, 0, 0
    for ab in AB:
        if ab < 0:
            cunt_a += -ab//2 # +2
            cunt_ab += -ab%2 # +1
        elif ab > 0: 
            cunt_b += ab # -1
    if cunt_b <= cunt_a:
        print("Yes")
    elif cunt_b > cunt_a:
        print("No")
        sys.exit()

    
    
if __name__=='__main__':
    main()