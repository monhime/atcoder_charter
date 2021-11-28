import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
sys.setrecursionlimit(1000000)
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, m = map(int,input().split())
    graph = [[] for _ in range(n)]
    for i in range(m):
        a, b = map(int,input().split())
        graph[a - 1].append(b - 1)

    def bfs(x):
        cunt = 1 #自分
        visited = [False] * n
        visited[x] = True
        queue = deque([x])
        while queue:
            node = queue.popleft()
            for xnode in graph[node]:
                if visited[xnode]:
                    continue
                visited[xnode] = True
                queue.append(xnode)
                cunt += 1
        return cunt
    ans = 0
    for i in range(n):
        ans += bfs(i)
    print(ans)


if __name__=='__main__':
    main()