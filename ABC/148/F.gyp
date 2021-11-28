import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n, u, v = map(int,input().split())
    if u == v:
        print(0)
        sys.exit()

    graph = [[] for _ in range(n)]
    depth_u = [-1] * (n) #頂点iのuから見た深さ
    depth_v = [-1] * (n) #頂点iのvから見た深さ
    u -= 1 #高橋
    v -= 1 #青木
    for i in range(n-1):
        a, b = map(int,input().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)
    
    # bfsで高橋から見た各頂点の深さをメモる。
    queue = deque([u])
    visited = [False]*n
    visited[u] = True
    depth_u[u] = 0
    while queue:
        node = queue.popleft()
        for xnode in graph[node]:
            if not visited[xnode]:
                visited[xnode] = True
                depth_u[xnode] = depth_u[node] + 1
                queue.append(xnode)
    # bfsで青木から見た各頂点の深さをメモる。
    queue = deque([v])
    visited = [False]*n
    visited[v] = True
    depth_v[v] = 0
    while queue:
        node = queue.popleft()
        for xnode in graph[node]:
            if not visited[xnode]:
                visited[xnode] = True
                depth_v[xnode] = depth_v[node] + 1
                queue.append(xnode)
    ans = 0
    max_d_v = 0
    for i in range(n):
        if depth_u[i] < depth_v[i]:
            max_d_v = max(max_d_v, depth_v[i])
    print(max_d_v - 1)



if __name__=='__main__':
    main()