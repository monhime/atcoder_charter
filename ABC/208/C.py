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
    A = [(i,int(x)) for i,x in enumerate(input().split())]
    B = [0] * n # i番目の人は余った分がもらえるか
    A.sort(key = itemgetter(1))
    for kk in range(k % n):
        B[A[kk][0]] = 1
    for i in range(n):
        print(k//n + B[i])
    
if __name__=='__main__':
    main()