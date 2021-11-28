import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, x = map(int,input().split())
    S = input()
    ans = x
    for s in S:
        if s == 'o':
            ans += 1
        elif ans > 0:
            ans -= 1
    print(ans)

if __name__=='__main__':
    main()