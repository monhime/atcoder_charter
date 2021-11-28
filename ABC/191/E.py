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


# Pythonで出せ PyPyはTLE
sys.setrecursionlimit(1000000)


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    graph_T = [[] for _ in range(n)]
    Me = [inf]*n
    for _ in range(m):
        a, b, c = map(int, input().split())
        if a != b:
            graph[a - 1].append((b - 1, c))
            graph_T[b - 1].append((a - 1, c))
        else:
            Me[a - 1] = min(Me[a - 1], c)
    ANS = [0] * n
    for i in range(n):
        queue = [(0, i)]
        ans = [inf] * n
        ans[i] = 0
        while queue:  # O(n+mlog(m))
            dist, node = heappop(queue)
            if dist > ans[node]:  # 既に早い時刻に更新されていた場合
                continue
            for xnode, c in graph[node]:
                x_t = dist + c
                if x_t >= ans[xnode]:
                    continue
                heappush(queue, (x_t, xnode))
                ans[xnode] = x_t
        queue = [(0, i)]
        ans_T = [inf] * n
        ans_T[i] = 0
        while queue:  # O(n+mlog(m))
            dist, node = heappop(queue)
            if dist > ans_T[node]:  # 既に早い時刻に更新されていた場合
                continue
            for xnode, c in graph_T[node]:
                x_t = dist + c
                if x_t >= ans_T[xnode]:
                    continue
                heappush(queue, (x_t, xnode))
                ans_T[xnode] = x_t
        min_ans = inf
        for j in range(n):
            min_ans = min(min_ans, ans[j] + ans_T[j] if i != j else Me[j])
        ANS[i] = min_ans if min_ans != inf else -1
    print("\n".join(map(str, ANS)))


if __name__ == '__main__':
    main()
