import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n=int(input())
    graph=[[] for _ in range(n)]
    for i in range(n-1):
        a,b=map(int,input().split())
        graph[a-1].append((b-1,i))
        graph[b-1].append((a-1,i))
    queue=deque([0])
    visited=[False]*n
    visited[0]=True
    colors=[0]*n
    ans=[0]*(n-1)
    while queue:
        node=queue.popleft()
        c=1
        for xnode,edge in graph[node]:
            if visited[xnode]:continue
            if colors[node]==c:c+=1
            ans[edge]=c
            colors[xnode]=c
            visited[xnode]=True
            queue.append(xnode)
            c+=1
    print(max(ans))
    for a in ans:
        print(a)

if __name__=='__main__':
    main()