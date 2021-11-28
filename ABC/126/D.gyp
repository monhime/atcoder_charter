import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n=int(input())
    graph=[[]for _ in range(n)]
    for _ in range(n-1):
        u,v,w=map(int,input().split())
        graph[u-1].append((v-1,w))
        graph[v-1].append((u-1,w))
    D=[-1]*n
    D[0]=0
    que=deque([0])
    while que:
        q=que.popleft()
        qw=D[q]
        for nn,w in graph[q]:
            if D[nn]==-1:
                D[nn]=qw+w
                que.append(nn)
    for d in D:
        if d%2==0:
            print(0)
        else:
            print(1)


if __name__=='__main__':
    main()