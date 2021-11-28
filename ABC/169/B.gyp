import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    ans = 1
    if 0 in A:
        print(0)
        sys.exit()
    for a in A:
        ans *= a
        if ans > 10**18:
            print(-1)
            break
    else:
        print(ans)

if __name__=='__main__':
    main()