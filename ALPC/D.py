from collections import deque
import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


class mf_graph:
    n = 1
    g = [[] for i in range(1)]
    pos = []

    def __init__(self, n):
        self.n = n
        self.g = [[] for i in range(n)]

    def add_edge(self, fr, to, cap):
        m = len(self.pos)
        self.pos.append((fr, len(self.g[fr])))
        self.g[fr].append({"to": to, "rev": len(self.g[to]), "cap": cap})
        self.g[to].append({"to": fr, "rev": len(self.g[fr])-1, "cap": 0})
        return m

    def get_edge(self, i):
        _e = self.g[self.pos[i][0]][self.pos[i][1]]
        _re = self.g[_e["to"]][_e["rev"]]
        return {"fr": self.pos[i][0],
                "to": _e["to"],
                "cap": _e["cap"]+_re["cap"],
                "flow": _re["cap"]}

    def edges(self):
        m = len(self.pos)
        return [self.get_edge(i) for i in range(m)]

    def change_edge(self, i, new_cap, new_flow):
        _e = self.g[self.pos[i][0]][self.pos[i][1]]
        _re = self.g[_e["to"]][_e["rev"]]
        _e["cap"] = new_cap-new_flow
        _re["cap"] = new_flow

    def flow(self, s, t, flow_limit=(2**31)-1):
        level = [0 for _ in range(self.n)]
        Iter = [0 for _ in range(self.n)]

        def bfs():
            for i in range(self.n):
                level[i] = -1
            level[s] = 0
            que = deque([])
            que.append(s)
            while len(que):
                v = que.popleft()
                for e in self.g[v]:
                    if e["cap"] == 0 or level[e["to"]] >= 0:
                        continue
                    level[e["to"]] = level[v] + 1
                    if e["to"] == t:
                        return
                    que.append(e["to"])

        def dfs(func, v, up):
            if v == s:
                return up
            res = 0
            level_v = level[v]
            for i in range(Iter[v], len(self.g[v])):
                e = self.g[v][i]
                if (level_v <= level[e["to"]] or self.g[e["to"]][e["rev"]]["cap"] == 0):
                    continue
                d = func(func, e["to"], min(
                    up - res, self.g[e["to"]][e["rev"]]["cap"]))
                if d <= 0:
                    continue
                self.g[v][i]["cap"] += d
                self.g[e["to"]][e["rev"]]["cap"] -= d
                res += d
                if res == up:
                    return res
            level[v] = self.n
            return res
        flow = 0
        while flow < flow_limit:
            bfs()
            if level[t] == -1:
                break
            for i in range(self.n):
                Iter[i] = 0
            while flow < flow_limit:
                f = dfs(dfs, t, flow_limit - flow)
                if not(f):
                    break
                flow += f
        return flow

    def min_cut(self, s):
        visited = [False for i in range(self.n)]
        que = deque([])
        que.append(s)
        while(len(que) > 0):
            p = que.popleft()
            visited[p] = True
            for e in self.g[p]:
                if e["cap"] and not(visited[e["to"]]):
                    visited[e["to"]] = True
                    que.append(e["to"])
        return visited


def main():
    mod = 10**9 + 7
    inf = 10**10

    n, m = map(int, input().split())
    S = [list(input()) for _ in range(n)]
    G = mf_graph(n * m + 2)
    for i in range(n):
        for j in range(m):
            if S[i][j] == '#':
                continue
            if (i + j) % 2 == 0:
                G.add_edge(n * m, i * m + j, 1)
            else:
                G.add_edge(i * m + j, n * m + 1, 1)
    for i in range(n):
        for j in range(m):
            if (i + j) % 2 == 1 or S[i][j] == '#':
                continue
            x = i * m + j
            if i - 1 >= 0 and S[i - 1][j] == '.':
                y = (i - 1) * m + j
                G.add_edge(x, y, 1)
            if i + 1 < n and S[i + 1][j] == '.':
                y = (i + 1) * m + j
                G.add_edge(x, y, 1)
            if j - 1 >= 0 and S[i][j - 1] == '.':
                y = i * m + (j - 1)
                G.add_edge(x, y, 1)
            if j + 1 < m and S[i][j + 1] == '.':
                y = i * m + (j + 1)
                G.add_edge(x, y, 1)
    print(G.flow(n * m, n * m + 1))
    for e in G.edges():
        if e["fr"] == n * m or e["to"] == n * m + 1 or e["flow"] == 0:
            continue
        fr_i = e["fr"] // m
        fr_j = e["fr"] % m
        to_i = e["to"] // m
        to_j = e["to"] % m
        if fr_i - 1 == to_i:
            S[fr_i][fr_j] = '^'
            S[to_i][to_j] = 'v'
        elif fr_i + 1 == to_i:
            S[fr_i][fr_j] = 'v'
            S[to_i][to_j] = '^'
        elif fr_j - 1 == to_j:
            S[fr_i][fr_j] = '<'
            S[to_i][to_j] = '>'
        elif fr_j + 1 == to_j:
            S[fr_i][fr_j] = '>'
            S[to_i][to_j] = '<'
    for i in range(n):
        print(''.join(S[i]))


if __name__ == '__main__':
    main()
