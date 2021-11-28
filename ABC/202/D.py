import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
from operator import mul
from functools import reduce
def combinations_count(n, r): #nCr
    #Reference: https://note.nkmk.me/python-math-factorial-permutations-combinations/
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    a, b, k  =map(int,input().split())
    C = [[0]*(b + 1) for _ in range(a + 1)] # C[i][j] aがi個，bがj個の総数
    C[0][0] = 1
    for i in range(a + 1):
        for j in range(b + 1):
            C[i][j] = combinations_count(i + j, i)
    def S(i, j, k):
        if i == 0:
            return "b"*j
        if j == 0:
            return "a"*i
        if k <= C[i - 1][j]:
            return "a" + S(i - 1, j, k)
        else:
            return "b" + S(i, j - 1, k - C[i - 1][j])

    print(S(a, b, k))

    
    
if __name__=='__main__':
    main()