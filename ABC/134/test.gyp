from subprocess import *
call(('pypy3','-c',"""
import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    n,q=map(int,input().split())
    P=[[] for _ in range(n)]
    for i in range(n-1):
        a,b=map(int,input().split())
        P[a-1].append(b-1)
        P[b-1].append(a-1)
    X=[0]*n
    for i in range(q):
        p,x=map(int,input().split())
        X[p-1]+=x
    deq=deque([0])
    visited=[False]*n 
    while deq:
        node=deq.popleft()
        if not(visited[node]):
            visited[node]=True
            for p in P[node]:
                if not(visited[p]):
                    X[p]+=X[node]
                    deq.append(p)
    print(*X)

if __name__=='__main__':
    main()
"""))