import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations, repeat
from operator import itemgetter
from typing import List
# sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    n = int(input())
    A = list(map(int, input().split()))
    if n > 8:
        n = 8
        A = A[:8]
    ANS = [[] for _ in range(200)]
    for bit_1 in range(1 << n):  # 2**n通りのbit_n番目を探索
        B = []
        mod_1 = 0
        for i in range(n):
            if (bit_1 >> i) & 1:  # bitのi桁目が1なら
                mod_1 = (mod_1 + A[i]) % 200
                B.append(i + 1)
        if len(ANS[mod_1]) > 0:
            print("Yes")
            print(len(ANS[mod_1]), " ".join(map(str, ANS[mod_1])))
            print(len(B), " ".join(map(str, B)))
            sys.exit()
        else:
            ANS[mod_1] = B
    else:
        print("No")


if __name__ == '__main__':
    main()
