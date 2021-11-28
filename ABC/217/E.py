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
    inf = math.inf

    q = int(input())
    A1 = deque()
    A2 = []
    for _ in range(q):
        s = input()
        if s[0] == "1":
            A1.append(int(s[2:]))
        elif s[0] == "2":
            if A2:
                print(heappop(A2))
            else:
                print(A1.popleft())
        else:
            while A1:
                heappush(A2, A1.popleft())


if __name__ == '__main__':
    main()
