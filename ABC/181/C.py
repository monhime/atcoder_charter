import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    XY = [[int(_) for _ in input().split()] for i in range(n)]

    for i in range(n):
        x_i = XY[i][0]
        y_i = XY[i][1]
        for j in range(i + 1, n):
            x_j = XY[j][0]
            y_j = XY[j][1]
            for k in range(j + 1, n):
                x_k = XY[k][0]
                y_k = XY[k][1]
                if (x_k - x_j)*(y_j - y_i) == (x_j - x_i)*(y_k - y_j):
                    print("Yes")
                    sys.exit()
    print("No")
                

if __name__=='__main__':
    main()