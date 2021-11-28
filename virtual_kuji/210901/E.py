import sys
import math
import copy
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
    inf = 10**11

    x, y, z, k = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    lis = [0]*(y*z)
    for i in range(y):
        for j in range(z):
            lis[i*z + j] = B[i] + C[j]
    lis.sort()

    ans = 0

    def f(x):
        #　和がxになるのは何番目？
        cunt = 0
        for a in A:
            cunt += y*z - bisect_left(lis, x - a)
        return cunt

    # k番目に大きい値を求める
    left = 0
    right = inf
    while right - left > 1:
        mid = (left + right)//2
        if f(mid) >= k:  # oooxxxx
            left = mid
        else:
            right = mid
    ans = []
    for a in A:
        for b in reversed(lis):
            if left < a + b:
                ans.append(a + b)
            else:
                break
    ans.sort(reverse=True)
    for s in ans:
        print(s)
    for _ in range(k - len(ans)):
        print(left)


if __name__ == '__main__':
    main()
