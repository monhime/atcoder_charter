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

    n, a, b, c = map(int, input().split())
    A = [a, b, c]
    S = [input() for _ in range(n)]
    ANS = []
    if sum(A) != 2:
        for s in S:
            if s == "AB":
                x = 0
                y = 1
            elif s == "AC":
                x = 0
                y = 2
            else:
                x = 1
                y = 2
            if A[x] > A[y]:
                x, y = y, x
            A[x] += 1
            A[y] -= 1
            if A[y] < 0:
                print("No")
                sys.exit()
            if x == 0:
                ANS.append("A")
            elif x == 1:
                ANS.append("B")
            else:
                ANS.append("C")
        print("Yes")
        print("\n".join(map(str, ANS)))
    else:
        for i, s in enumerate(S):
            if s == "AB":
                x = 0
                y = 1
            elif s == "AC":
                x = 0
                y = 2
            else:
                x = 1
                y = 2
            if A[x] != A[y] or i == n - 1 or S[i + 1] == S[i]:
                if A[x] > A[y]:
                    x, y = y, x
                A[x] += 1
                A[y] -= 1
                if x == 0:
                    ANS.append("A")
                elif x == 1:
                    ANS.append("B")
                else:
                    ANS.append("C")
            else:
                if S[i + 1] == "AB":
                    if s == "AC":
                        A[0] += 1
                        A[2] -= 1
                        ANS.append("A")
                    elif s == "BC":
                        A[1] += 1
                        A[2] -= 1
                        ANS.append("B")
                elif S[i + 1] == "AC":
                    if s == "AB":
                        A[0] += 1
                        A[1] -= 1
                        ANS.append("A")
                    elif s == "BC":
                        A[2] += 1
                        A[1] -= 1
                        ANS.append("C")
                elif S[i + 1] == "BC":
                    if s == "AB":
                        A[1] += 1
                        A[0] -= 1
                        ANS.append("B")
                    elif s == "AC":
                        A[2] += 1
                        A[0] -= 1
                        ANS.append("C")
            if A[y] < 0:
                print("No")
                sys.exit()
        print("Yes")
        print("\n".join(map(str, ANS)))


if __name__ == '__main__':
    main()
