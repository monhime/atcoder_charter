import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, k = map(int,input().split())
    if k > (n - 1)*(n - 2)//2:
        print(-1)
        sys.exit()
    
    cunt = (n - 1)*(n - 2)//2 - k#追加する辺の数
    print(cunt +  n - 1)
    for i in range(2, n + 1): #ウニ
        print(1, i)
    for i in range(2, n + 1):
        for j in range(i + 1, n + 1):
            if cunt > 0:
                print(i, j)
                cunt -= 1
            else:
                sys.exit()


if __name__=='__main__':
    main()