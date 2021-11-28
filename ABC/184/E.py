import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque

def main():
    h, w = map(int,input().split())
    A = [input() for i in range(h)]
    graph = [[] for _ in range(ord('z') - ord('a') + 1)]

    for i in range(1, h + 1):
        for j in range(1, w + 1):
            idx = j + i * (w + 2)
            if A[i - 1][j - 1] == 'S':
                start = idx
            elif A[i - 1][j - 1] == 'G':
                goal = idx               
            elif ord(A[i - 1][j - 1]) >= ord('a') and ord(A[i - 1][j - 1]) <= ord('z') :
                graph[ord(A[i - 1][j - 1]) - ord('a')].append(idx)
    
    ans = [-1] * ((h + 2) * (w + 2))
    ans[start] = 0
    queue = deque([start])
    visited = [False] * ((h + 2) * (w + 2))
    visited[start] = True
    while queue:
        node = queue.popleft()
        y = node // (w + 2)
        x = node % (w + 2)
        if ord(A[y - 1][x - 1]) >= ord('a') and ord(A[y - 1][x - 1]) <= ord('z') and len(graph[ord(A[y - 1][x - 1]) - ord('a')]) > 0:
            for xnode in graph[ord(A[y - 1][x - 1]) - ord('a')]:
                if visited[xnode]:
                    continue
                visited[xnode] = True
                queue.append(xnode)
                ans[xnode] = ans[node] + 1 
                 
                if xnode == goal:
                    print(ans[goal])
                    sys.exit()
            graph[ord(A[y - 1][x - 1]) - ord('a')] = []

        for next_idx in [w + 2, -(w + 2), 1, -1]:
            xnode = node + next_idx
            y = xnode // (w + 2)
            x = xnode % (w + 2)
            #行ったことあるか、袖領域ならcontinue
            if y == 0 or y == h + 1 or x == 0 or x == w + 1 or visited[xnode] or A[y - 1][x - 1] == '#':
                continue
            visited[xnode] = True
            queue.append(xnode)
            ans[xnode] = ans[node] + 1
        
            if xnode == goal:
                print(ans[goal])
                sys.exit()
    else:
        print(-1)

if __name__=='__main__':
    main()