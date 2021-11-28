import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n = int(input())
    graph = [[] for _ in range(n)]
    edge = []
    ans = [0] * n #各頂点のc

    for i in range(n - 1):
        a, b = map(int,input().split())
        a -= 1
        b -= 1
        graph[a].append(b)
        graph[b].append(a)
        edge.append((a, b))

    # 木の深さ記録
    depth = [-1] * n
    depth[0] = 0
    queue = deque([0])
    while queue: 
        node = queue.popleft()
        for xnode in graph[node]:
            if depth[xnode] >= 0:
                continue
            depth[xnode] = depth[node] + 1
            queue.append(xnode)
            
    s = [0] * n
    q = int(input())
    for i in range(q):
        t, e, x = map(int,input().split())
        e -= 1
        a, b = edge[e]
        if depth[a] < depth[b]:
            if t == 1:
                s[0] += x
                s[b] -= x
            else:
                s[b] += x
        else:
            if t == 1:
                s[a] += x
            else:
                s[0] += x
                s[a] -= x

    queue = deque([0])
    while queue:
        node = queue.popleft()
        for xnode in graph[node]:
            if depth[node] > depth[xnode]:
                continue
            s[xnode] += s[node]
            queue.append(xnode)
    for ss in s:
        print(ss)

if __name__=='__main__':
    main()