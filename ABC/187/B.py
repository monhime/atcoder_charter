import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    XY = [[int(_) for _ in input().split()] for i in range(n)]
    ans = 0
    for i in range(n):
        x_i = XY[i][0]
        y_i = XY[i][1]
        for j in range(i + 1, n):
            x_j = XY[j][0]
            y_j = XY[j][1]
            if abs(x_j - x_i) >= abs(y_j - y_i):
                ans += 1
    print(ans)


if __name__=='__main__':
    main()