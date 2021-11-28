import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    graph_c = [[] * n]
    graph = [[] * n]
    ans = [0]*n
    A = [tuple(map(int,input().split())) for i in range(n)]

    for i in range(n):
        a, b = A[i]
        graph[a-1].append(b-1)
        graph[b-1].append(a-1)

    q = int(input())
    for i in range(q):
        t, e, x = map(int,input().split())
        e -= 1
        if t == 1:
            graph_c[A[e][1]][A[e][0]] += x
        else:
            graph_c[A[e][0]][A[e][1]] += x
        
    queue = deque([0])
    visited = [False]*n
    visited[0] = True
    while queue:
        node = queue.popleft()
        for xnode in graph[node]:
            if not visited[xnode]:
                visited[xnode] = True
                queue.append(xnode)
                ans[xnode] += graph_c[node][xnode]
                last_node = xnode

    queue = deque([last_node])
    visited = [False]*n
    visited[0] = True
    while queue:
        node = queue.popleft()
        for xnode in graph[node]:
            if not visited[xnode]:
                visited[xnode] = True
                queue.append(xnode)
                ans[xnode] += graph_c[node][xnode]
    for a in ans:
        print(ans)

if __name__=='__main__':
    main()