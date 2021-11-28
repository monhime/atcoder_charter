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

    h, w = map(int, input().split())
    S = [input() for _ in range(h)]
    ans = 0
    visited = [[-1]*w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            idx = i * w + j
            if visited[i][j] or S[i][j] == "#":
                continue
            cunt = 0
            queue = deque([idx])
            visited[i][j] = 1
            while queue:
                node = queue.popleft()
                for next_idx in [w, -w, 1, -1]:
                    xnode = node + next_idx
                    y = xnode // w
                    x = xnode % w
                    if y < 0 or y >= h or x < 0 or x >= w or visited[y][x] >= 0 or S[y][x] == '#':
                        continue
                    queue.append(xnode)
                    visited[y][x] = visited[i][j] + 1
                    cunt = max(cunt, visited[y][x])


if __name__ == '__main__':
    main()
