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


class BIT:
    def __init__(self, n):
        self.unit_sum = 0  # to be set
        self.n = n
        self.dat = [0]*(n + 1)  # [1, n]を使う。

    def add(self, a, x):  # a(1-)
        i = a
        while i <= self.n:
            self.dat[i] += x
            i += i & -i  # 担当する区間の長さ（最下位bit）だけ足すと次に更新すべき区間になる

    def sum(self, a, b=None):  # 区間[a, b)の和を求める or 区間[1,a]の和を求める
        if b != None:
            # [a,b) a(1-),b(1-)（xorのときはself.sum(b-1）^self.sum(a-1)
            return self.sum(b - 1)-self.sum(a - 1)
        res = self.unit_sum
        i = a
        while i > 0:
            res += self.dat[i]
            i -= i & -i
        return res  # Σ[1,a] a(1-)

    def __str__(self):
        self.ans = []
        for i in range(1, self.n):
            self.ans.append(self.sum(i, i+1))
        return ' '.join(map(str, self.ans))


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7
    inf = 10**10

    n = int(input())
    A = list(map(int, input().split()))

    _BIT = BIT(n)
    cunt = 0
    for j in range(n):
        cunt += j - _BIT.sum(A[j] + 1)
        _BIT.add(A[j] + 1, 1)
    print(cunt)
    for k in range(n - 1):
        cunt += n - 1 - 2*A[k]
        print(cunt)


if __name__ == '__main__':
    main()
