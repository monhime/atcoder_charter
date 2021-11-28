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
    h, w = map(int, input().split())
    S = ["#" * (w + 2) for _ in range(h + 2)]
    for i in range(1, h + 1):
        S[i] = "#" + input() + "#"
    cunt_s = 0
    for i in range(1, h + 1):
        for j in range(1, w + 1):
            if S[i][j] == "#":
                cunt_s += 1
    ans = [-1] * ((h + 2) * (w + 2))
    ans[w + 3] = 0
    queue = deque([w + 3])
    visited = [False] * ((h + 2) * (w + 2))
    visited[w + 3] = True
    while queue:
        node = queue.popleft()
        for next_idx in [w + 2, -(w + 2), 1, -1]:
            xnode = node + next_idx
            y = xnode // (w + 2)
            x = xnode % (w + 2)
            if visited[xnode] or S[y][x] == '#':
                continue
            visited[xnode] = True
            queue.append(xnode)
            ans[xnode] = ans[node] + 1
    if ans[(w + 2) * h + w] == -1:
        print(-1)
    else:
        print(h*w - ans[(w + 2)*h + w] - cunt_s - 1)


if __name__ == '__main__':
    main()
