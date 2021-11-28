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

    s = input()
    if len(s) == 2:
        if int(s) % 8 == 0 or int(s[::-1]) % 8 == 0:
            print("Yes")
        else:
            print("No")
        sys.exit()
    elif len(s) == 1:
        if int(s) % 8 == 0:
            print("Yes")
        else:
            print("No")
        sys.exit()

    s_c = Counter(s)
    for i in range(125):
        n = 8*i
        n_s = f"{n:03}"
        n_s_c = Counter(n_s)
        for n_s_c_k, n_s_c_v in n_s_c.items():
            if s_c[n_s_c_k] < n_s_c_v:
                break
        else:
            print("Yes")
            break
    else:
        print("No")


if __name__ == '__main__':
    main()
