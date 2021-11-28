import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    n, s, d = map(int,input().split())
    XY = [[int(_) for _ in input().split()] for i in range(n)]
    XY.sort()
    for x, y in XY:
        if x < s and y > d:
            print("Yes")
            exit()
        elif x >= s:
            print("No")
            exit()
    print("No")
    
    
if __name__=='__main__':
    main()