import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n,m=map(int,input().split())
    graph=[[] for _ in range(n)]
    for i in range(m):
        a,b=map(int,input().split())
        graph[a-1].append(b-1)
        graph[b-1].append(a-1)
    queue=deque([0])
    visited=[False]*n
    visited[0]=True
    ans=[0]*n
    while queue:
        node=queue.popleft()
        for xnode in graph[node]:
            if visited[xnode]:continue
            ans[xnode]=node+1
            visited[xnode]=True
            queue.append(xnode)
    print("Yes")
    for a in ans[1:]:
        print(a)


if __name__=='__main__':
    main()