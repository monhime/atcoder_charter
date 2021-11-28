import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def main():
    r,c=map(int,input().split())
    sy,sx=map(int,input().split())
    sy-=1
    sx-=1
    gy,gx=map(int,input().split())
    gy-=1
    gx-=1
    C=[input() for _ in range(r)] #0~(r-1)*0~(c-1)
    A=[0]*(c*r)
    queue=deque([c*sy+sx])
    visited=[False]*(r*c)
    visited[c*sy+sx]=True
    ans=0
    while queue:
        yx=queue.popleft()
        y=yx//c
        x=yx%c
        for ny,nx in [(y+1,x),(y-1,x),(y,x+1),(y,x-1)]:
            if ny<0 or ny>=r or nx<0 or nx>=c or C[ny][nx]=="#":continue
            nyx=ny*c+nx
            if visited[nyx]:continue
            if nyx==gy*c+gx:
                print(A[y*c+x]+1)
                sys.exit()
            visited[nyx]=True
            queue.append(nyx)
            A[ny*c+nx]=A[y*c+x]+1

if __name__=='__main__':
    main()