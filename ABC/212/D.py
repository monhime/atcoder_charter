import heapq
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
    
    q = int(input())
    H = []
    offset = 0
    for i in range(q):
        s = input()
        if s[0] == "1":
            _, x = map(int, s.split())
            heappush(H, x - offset)
        if s[0] == "2":
            _, x = map(int, s.split())
            offset += x 
        if s[0] == "3":
            print(heappop(H) + offset)
        
    
if __name__=='__main__':
    main()