import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    h, w, n, m = map(int,input().split())
    AB = [[int(_) for _ in input().split()] for i in range(n)]
    CD = [[int(_) for _ in input().split()] for i in range(m)]
    Masu_light = [[False]*w for i in range(h)]
    Masu_block = [[False]*w for i in range(h)]
    Masu_right = [[False]*w for i in range(h)] 
    Masu_left = [[False]*w for i in range(h)] 
    Masu_up = [[False]*w for i in range(h)]
    Masu_down = [[False]*w for i in range(h)]   

    for ab in AB:
        Masu_light[ab[0] - 1][ab[1] - 1] = True
    for cd in CD:
        Masu_block[cd[0] - 1][cd[1] - 1] = True
    
    for i in range(h):
        light = False
        for j in range(w):
            if Masu_light[i][j]:
                light = True
            elif Masu_block[i][j]:
                light = False

            if light == True:
                Masu_right[i][j] = True
        light = False
        for j in range(w - 1, -1, -1):
            if Masu_light[i][j]:
                light = True
            elif Masu_block[i][j]:
                light = False

            if light == True:
                Masu_right[i][j] = True   

    for j in range(w):
        light = False
        for i in range(h):
            if Masu_light[i][j]:
                light = True
            elif Masu_block[i][j]:
                light = False

            if light == True:
                Masu_down[i][j] = True
        light = False
        for i in range(h - 1, -1, -1):
            if Masu_light[i][j]:
                light = True
            elif Masu_block[i][j]:
                light = False

            if light == True:
                Masu_right[i][j] = True   
    ans = 0
    for i in range(h):
        for j in range(w):
            if Masu_right[i][j] or Masu_left[i][j] or Masu_up[i][j] or Masu_down[i][j]:
                ans += 1
    print(ans)

if __name__=='__main__':
    main()