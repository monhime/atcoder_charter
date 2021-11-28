import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
import numpy as np
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    C = [[int(_) for _ in input().split()] for i in range(n)]
    dx_C = [[0]*(n - 1) for _ in range(n)]
    dy_C = [[0]*(n) for _ in range(n - 1)]
    for i in range(n):
        for j in range(n - 1):
            dx_C[i][j] = C[i][j + 1] - C[i][j]
            if i >= 1 and dx_C[i][j] != dx_C[i - 1][j]:
                print("No")
                sys.exit()

    for i in range(n - 1):
        for j in range(n):
            dy_C[i][j] = C[i + 1][j] - C[i][j]
            if j >= 1 and dy_C[i][j] != dy_C[i][j - 1]:
                print("No")
                sys.exit()    

    print("Yes")
    np_C = np.array(C)
    print(" ".join(map(str, np_C[:, 0] - np.min(np_C[:, 0]))))
    print(" ".join(map(str, np.min(np_C, axis = 0))))

if __name__=='__main__':
    main()