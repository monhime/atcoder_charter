import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
from functools import cmp_to_key
# sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


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

    def sum(self, a, b=None):  # 区間[a(1-), b(1-))の和を求める or 区間[1,a(1-)]の和を求める
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


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    n, q = map(int, input().split())
    C = list(map(int, input().split()))
    C = [c - 1 for c in C]
    LR = [[int(_) for _ in input().split()] for i in range(q)]
    LR = [[i, l - 1, r] for i, (l, r) in enumerate(LR)]
    LR.sort(key=itemgetter(2))
    Bit = BIT(n)
    ANS = [0]*q
    cur_r = -1
    c_idx = [-1]*n
    for idx, l, r in LR:
        for j in range(cur_r + 1, r):
            if c_idx[C[j]] != -1:
                Bit.add(c_idx[C[j]] + 1, -1)
            c_idx[C[j]] = j
            Bit.add(j + 1, 1)
        cur_r = r - 1
        ANS[idx] = Bit.sum(l + 1, r + 1)
    print("\n".join(map(str, ANS)))


if __name__ == '__main__':
    main()
