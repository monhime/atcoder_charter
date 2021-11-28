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
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    n, m, k = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A_acc = list(accumulate(A))
    B_acc = list(accumulate(B))
    ans = bisect_right(B_acc, k)
    # print(A_acc)
    # print(B_acc)
    for i, a in enumerate(A_acc):
        if a > k:
            break
        ans = max(ans, i + bisect_right(B_acc, k - a) + 1)
        # print(i, k - a, bisect_right(B_acc, k - a), ans)
    print(ans)


if __name__ == '__main__':
    main()
