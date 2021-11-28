import sys
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import math
def input(): return sys.stdin.readline().rstrip()
def f(x):
    s_x = str(x)
    g_1 = ''.join(sorted(s_x, reverse = True))
    g_2 = ''.join(sorted(s_x))
    return int(g_1) - int(g_2)

def main():
    mod = 10**9 + 7
    
    n, k = map(int,input().split())

    a = n
    for i in range(k):
        a = f(a)
    print(a)
    
if __name__=='__main__':
    main()