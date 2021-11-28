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


class Sieve2:  # √nまでの素因数で試し割り 前処理O(√nloglogn+√n/logn)
    def __init__(self, n):
        self.primes = []
        self.f = [0]*(int(n**0.5)+1)  # ふるい（素数ならその値）
        self.f[0] = self.f[1] = -1
        for i in range(2, int(n**0.5)+1):  # 素数リスト作成
            if self.f[i]:
                continue
            self.primes.append(i)
            self.f[i] = i
            for j in range(i*i, int(n**0.5)+1, i):
                if not self.f[j]:
                    self.f[j] = i  # 最小の素因数を代入

    def prime_fact(self, x):  # 素因数分解 {2:p,3:q,5:r,...}
        fact_dict = dict()
        for p in self.primes:
            if p*p > x:
                break
            while x % p == 0:
                x //= p
                fact_dict[p] = fact_dict.get(p, 0)+1
        if x > 1:
            fact_dict[x] = fact_dict.get(x, 0)+1
        return fact_dict


def main():
    mod = 10**9 + 7
    inf = 10**10

    n = int(input())
    SEIVE = Sieve2(n)
    dic = dict()
    for i in range(1, n + 1):
        fac = SEIVE.prime_fact(i)
        for k, v in fac.items():
            dic[k] = dic.get(k, 0) + v
    ans = 0
    cunt_74, cunt_24, cunt_14, cunt_4, cunt_2 = 0, 0, 0, 0, 0
    for v in dic.values():
        if v >= 74:
            cunt_74 += 1
        if v >= 24:
            cunt_24 += 1
        if v >= 14:
            cunt_14 += 1
        if v >= 4:
            cunt_4 += 1
        if v >= 2:
            cunt_2 += 1
    print(cunt_74
          + max((cunt_2 - 1)*cunt_24, 0)
          + max((cunt_4 - 1)*cunt_14, 0)
          + max((cunt_2 - 2)*cunt_4*(cunt_4 - 1)//2, 0))


if __name__ == '__main__':
    main()
