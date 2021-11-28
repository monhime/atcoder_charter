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
    inf = 10**10
    A = list(map(int, input().split()))
    E = list(product(['+', '-', '/', '*'], repeat=3))
    for a_l in list(permutations(A)):
        for e in E:
            ans = a_l[0]
            for i, ee in enumerate(e):
                if ee == "+":
                    ans += a_l[i + 1]
                if ee == "-":
                    ans -= a_l[i + 1]
                if ee == "*":
                    ans *= a_l[i + 1]
                if ee == "/":
                    ans = math.floor(ans/a_l[i + 1])
            else:
                print(a_l, e, ans)
                if ans == 10 or ans == -10:
                    print(a_l)
                    print(e)
                    sys.exit()

    E = list(product(['+', '-', '/', '*'], repeat=2))
    for i in range(4):
        for j in range(4):
            if i == j:
                continue
            A2 = [10*A[i] + A[j]]
            for k in range(4):
                if k != i and k != j:
                    A2.append(A[k])
            for a_l in list(permutations(A2)):
                for e in E:
                    ans = a_l[0]
                    for i, ee in enumerate(e):
                        if ee == "+":
                            ans += a_l[i + 1]
                        if ee == "-":
                            ans -= a_l[i + 1]
                        if ee == "*":
                            ans *= a_l[i + 1]
                        if ee == "/":
                            ans = math.floor(ans/a_l[i + 1])
                    else:
                        print(a_l, e, ans)
                        if ans == 10 or ans == -10:
                            print(a_l)
                            print(e)
                            sys.exit()
    E = list(['+', '-', '/', '*'])
    for i in range(4):
        for j in range(4):
            for k in range(4):
                if i == j or j == k or i == k:
                    continue
                A3 = [100*A[i] + 10*A[j] + A[k]]
                A3.append(A[6 - (i + j + k)])
                for a_l in list(permutations(A3)):
                    for e in E:
                        ans = a_l[0]
                        for i, ee in enumerate(e):
                            if ee == "+":
                                ans += a_l[i + 1]
                            if ee == "-":
                                ans -= a_l[i + 1]
                            if ee == "*":
                                ans *= a_l[i + 1]
                            if ee == "/":
                                ans = math.floor(ans/a_l[i + 1])
                        else:
                            print(a_l, e, ans)
                            if ans == 10 or ans == -10:
                                print(a_l)
                                print(e)
                                sys.exit()


if __name__ == '__main__':
    main()
