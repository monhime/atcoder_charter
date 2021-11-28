import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque
def bfs(start):#global:h,w,maze
    que=deque([start])
    D=[-1]*(h*w)
    D[start]=0
    while que:
        x=que.popleft()
        for next_x in (x+1,x-1,x+w,x-w):
            if maze[next_x]=='.' and D[next_x]==-1:
                D[next_x]=D[x]+1
                que.append(next_x)
    return max(D)

def main():
    global h,w,maze
    h,w=map(int,input().split())
    h+=2
    w+=2
    maze="#"*w
    for _ in range(h-2):
        maze+="#"+input()+"#"
    maze+="#"*w 
    print(max(bfs(i) for i,c in enumerate(maze) if c=='.'))


if __name__=='__main__':
    main()


