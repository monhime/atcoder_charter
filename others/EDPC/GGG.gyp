import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n,m=map(int,input().split())
    XY=[tuple(map(int,input().split())) for i in range(m)]
    graph=[[]for _ in range(n)]
    deg=[0]*n #頂点iの入次数
    for x,y in XY:
        graph[x-1].append(y-1)
        deg[y-1]+=1
    que=deque()
    for v in range(n):
        if deg[v]==0:
            que.append(v)
    dp=[0]*n
    while que:
        v=que.popleft()
        for nv in graph[v]:
            deg[nv]-=1
            if deg[nv]==0:
                que.append(nv)
                dp[nv]=max(dp[nv],dp[v]+1)
    ans=0
    for v in range(n):
        ans=max(ans,dp[v])
    print(ans)

if __name__=='__main__':
    main()