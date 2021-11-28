import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n, m = map(int,input().split())
    A = list(map(int,input().split()))
    graph = [[] for _ in range(n)]
    for i in range(m):
        x, y = map(int,input().split())
        x -= 1
        y -= 1

        graph[y].append(x) #逆順

    max_value = [-10**11] * n
    for start_node in range(n - 1, -1, -1):
        queue = deque([start_node])
        while queue:
            node = queue.popleft()
            for xnode in graph[node]:
                if max_value[xnode] < max(max_value[xnode], max(A[node], max_value[node])): 
                    queue.append(xnode)
                    max_value[xnode] = max(max_value[xnode], max(A[node], max_value[node]))
    ans = -10**11
    for i in range(n):
        ans = max(ans, max_value[i] - A[i])
    print(ans)

if __name__=='__main__':
    main()