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
    
    s = int(input())
    a = s
    i = 1
    if a != 4:
        pre_4 = -1
    else:
        pre_4 = 0
    if s <= 2:
        print(4)
        sys.exit()
    while True:
        i +=1
        if a % 2 == 0:
            a = a//2
        else:
            a = 3*a + 1
        if a == 4:
            if pre_4 == -1:
                pre_4 = i
            else:
                print(i)
                sys.exit()
    
    
if __name__=='__main__':
    main()