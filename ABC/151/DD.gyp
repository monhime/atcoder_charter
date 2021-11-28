# D - Maze Master
from collections import deque


def bfs(start: int):
    queue = deque([start])
    dist = [0] * (H * W)
    dist[start] = 1
    while queue:
        x = queue.popleft()
        for nx in (x + 1, x - 1, x + W, x - W):
            if maze[nx] == "." and not dist[nx]:
                dist[nx] = dist[x] + 1
                queue.append(nx)
    return max(dist) - 1


def main():
    global H, W, maze
    H, W = map(int, input().split())
    H, W = H + 2, W + 2
    maze = "#" * W
    for _ in range(H - 2):
        maze += "#" + input().rstrip() + "#"
    maze += "#" * W
    ans = max(bfs(i) for i, c in enumerate(maze) if c == ".")
    print(ans)


if __name__ == "__main__":
    main()
